"""
/**
 * @file SuiteManager.py
 * @brief SuiteManager.py
 *
 * @testcase SuiteManager
 * @details Orchestrates the HDMI CEC Source L2 test suite by dynamically loading and executing
 *          test case modules, activating and initializing the required RDK plugins for each test,
 *          and reporting per-test pass/fail/skip results with summary statistics.
 *
 * @precondition
 *  - WPEFramework is running and reachable at the configured JSON-RPC endpoint.
 *  - The org.rdk.HdmiCecSource plugin is available for activation.
 *  - All test case modules listed in SUITES are present under the Testcases/ directory.
 *
 * @dependencies
 *  - utils.py
 *  - HdmiCECSource_Curl.py
 *  - Testcases/*.py
 *
 * @expected_result
 *  - All selected test cases are executed in order and results are logged.
 *
 * @pass_criteria
 *  - Each test case module's run_test() returns True (PASSED) or utils.SKIPPED
 *    (SKIPPED because an external precondition was not met).
 *
 * @failure_criteria
 *  - Any test case returns another value, raises an exception, or suite setup/cleanup fails.
 */
"""

import importlib
import io
import os
import sys
import time
from pathlib import Path

from utils import (
    PLUGIN_INIT_WAIT,
    SKIPPED,
    WPEFRAMEWORK_JSONRPC_URL,
    activate_plugin,
    deactivate_plugin,
    log_error,
    log_info,
    log_success,
    log_warning,
)


BASE_DIR = Path(__file__).resolve().parent
SUITES = {
    "hdmicecsource": {
        "banner": "******************** L2 SUITE - RDK - HDMI CEC SOURCE ****************************",
        "module_dir": BASE_DIR / "Testcases",
        "tests": [
            "TCID01_Send_Standby_Message",
            "TCID02_Get_Devicelist",
            "TCID03_Get_Enabled_Status",
            "TCID04_Get_OTP_Enabled",
            "TCID05_Get_Vendor_ID",
            "TCID06_Perform_OTP_Action",
            "TCID07_Send_Keypress_Event",
            "TCID08_Set_Enabled_False",
            "TCID09_Set_Enabled_True",
            "TCID10_Set_OTP_Name",
            "TCID11_Set_OTP_Enabled_False",
            "TCID12_Set_OTP_Enabled_True",
            "TCID13_Set_Vendor_ID",
            "TCID14_Verify_Vendor_ID_Readback",
            "TCID15_Get_OSD_Name",
            "TCID16_OTP_After_Powerstatus_Reporting",
            "TCID17_Menu_Language_CECversion_Flow",
            "TCID18_Active_Source_Routing_View_ON_Flow",
            "TCID19_Standby_OTP_Powerstatus_Flow",
            "TCID20_Standby_OTP_Userdef_CEC",
            "TCID21_Add_Remove_Device_Vcomponent",
            "TCID22_Verify_Devicelist_CEC_Disabled",
            "TCID23_Disable_CEC_Verify_Enabled",
            "TCID24_Standby_Userdef_Busstatus",
            "TCID25_Add_Network_Verify_Discovery",
            "TCID26_Standby_Then_OTP_Wakeup",
            "TCID27_Active_Source_Transition_After_OTP",
            "TCID28_Invalid_VendorID_Nochange",
            "TCID29_Repeated_Disable_Idempotent",
            "TCID30_Repeated_Enable_Idempotent",
            "TCID31_Invalid_OTP_Setnochange",
            "TCID32_Invalid_OSD_Setnochange",
            "TCID33_Process_Yaml_Health_Check",
        ],
    },
}

SUITE_PLUGIN_CALLSIGNS = {
    "hdmicecsource": ["org.rdk.HdmiCecSource"],
}

SUITE_PREREQUISITE_CALLSIGNS = {
    "hdmicecsource": [],
}

SUITE_INIT_MODULES = {
    "hdmicecsource": "Init_Devicelist_Populate",
}

SUITE_LIFECYCLES = {
    "hdmicecsource": "per_test",
}


def normalize_suite_name(raw_name):
    return raw_name.strip().replace("_", "").replace("-", "").lower()


def normalize_test_name(raw_name):
    return raw_name.strip().replace("_", "").replace("-", "").lower()


def resolve_selected_tests(suite_name, requested_tests):
    if not requested_tests:
        return list(SUITES[suite_name]["tests"])

    available_tests = SUITES[suite_name]["tests"]
    resolved = []

    for requested in requested_tests:
        requested_norm = normalize_test_name(requested)
        matches = [
            name
            for name in available_tests
            if normalize_test_name(name) == requested_norm
        ]
        if not matches:
            raise ValueError(
                f"Unknown test '{requested}'. Available tests: {available_tests}"
            )
        resolved.extend(matches)

    return resolved


def load_test_cases(suite_name, selected_tests=None):
    suite_config = SUITES[suite_name]
    module_dir = str(suite_config["module_dir"])

    if module_dir not in sys.path:
        sys.path.insert(0, module_dir)

    test_cases = []
    for module_name in resolve_selected_tests(suite_name, selected_tests):
        module = importlib.import_module(module_name)
        run_fn = getattr(module, "run_test", None)
        if not callable(run_fn):
            module_file = getattr(module, "__file__", "<unknown>")
            exported = [name for name in dir(module) if not name.startswith("__")]
            raise AttributeError(
                f"Module '{module_name}' from '{module_file}' does not expose callable run_test(). "
                f"Exported names: {exported}"
            )
        test_cases.append((module_name, run_fn))

    return suite_config["banner"], test_cases


def run_suite_init(suite_name):
    module_name = SUITE_INIT_MODULES.get(suite_name)
    if not module_name:
        return True

    base_dir = str(BASE_DIR)
    if base_dir not in sys.path:
        sys.path.insert(0, base_dir)

    try:
        module = importlib.import_module(module_name)
    except Exception as exc:
        log_error(f"Init module import failed: {module_name} ({exc})")
        return False

    run_fn = getattr(module, "run_test", None)
    if not callable(run_fn):
        log_error(f"Init module missing run_test(): {module_name}")
        return False

    log_info(f"Running suite initialization: {module_name}.run_test()")
    try:
        ok = run_fn() is True
    except Exception as exc:
        log_error(f"Suite initialization threw exception: {exc}")
        return False

    if ok:
        log_success("Suite initialization completed successfully")
    else:
        log_error("Suite initialization failed")
    return ok


def activate_test_plugins(suite_name):
    callsigns = list(SUITE_PREREQUISITE_CALLSIGNS.get(suite_name, []))
    callsigns.extend(SUITE_PLUGIN_CALLSIGNS.get(suite_name, []))

    activated = []
    for callsign in callsigns:
        log_info(
            f"Auto-activating plugin '{callsign}' "
            f"via curl JSON-RPC at {WPEFRAMEWORK_JSONRPC_URL}"
        )
        if not activate_plugin(callsign):
            log_error(f"Plugin activation failed: {callsign}")
            return False, activated
        activated.append(callsign)
        log_success(f"Plugin activated: {callsign}")
        log_info(
            f"Waiting {PLUGIN_INIT_WAIT}s for plugin to fully initialise..."
        )
        time.sleep(PLUGIN_INIT_WAIT)

    return True, activated


def deactivate_test_plugins(callsigns):
    success = True
    for callsign in reversed(callsigns):
        log_info(f"Auto-deactivating plugin '{callsign}'")
        if deactivate_plugin(callsign):
            log_success(f"Plugin deactivated: {callsign}")
        else:
            log_error(f"Plugin deactivation failed: {callsign}")
            success = False
    return success


def run_suite(suite_name, selected_tests=None):
    lifecycle = SUITE_LIFECYCLES.get(suite_name)
    if lifecycle != "per_test":
        raise ValueError(
            f"Unsupported lifecycle '{lifecycle}' for suite '{suite_name}'"
        )

    banner, test_cases = load_test_cases(suite_name, selected_tests)
    print(banner)
    log_info(f"Plugin lifecycle: {lifecycle}")

    auto_activate = (
        os.environ.get("AUTO_ACTIVATE_PLUGINS", "1").lower()
        not in ("0", "false", "no")
    )

    passed = 0
    failed = 0
    skipped = 0
    skipped_cases = []
    failed_cases = []
    original_stdout = sys.stdout

    for tc_name, tc_fn in test_cases:
        log_info(f"\n{'='*60}")
        log_info(f"Running: {tc_name}")
        log_info(f"{'='*60}")
        captured = io.StringIO()
        activated_callsigns = []
        result = False
        sys.stdout = captured
        try:
            plugins_ready = True
            if auto_activate:
                plugins_ready, activated_callsigns = activate_test_plugins(
                    suite_name
                )

            if not plugins_ready:
                log_error(
                    "Test setup failed because plugin activation did not complete."
                )
            elif not run_suite_init(suite_name):
                log_error(
                    "Test setup failed because initialization did not complete."
                )
            else:
                try:
                    result = tc_fn()
                except Exception as exc:
                    result = False
                    print(f"EXCEPTION in {tc_name}: {exc}")
        finally:
            try:
                if (
                    auto_activate
                    and not deactivate_test_plugins(activated_callsigns)
                ):
                    log_error("Test cleanup failed")
                    result = False
            finally:
                sys.stdout = original_stdout

        output = captured.getvalue()
        print(output, end="")

        if result == SKIPPED:
            skipped += 1
            skipped_cases.append(tc_name)
            log_warning(f"[SKIP] {tc_name}")
        elif result is True:
            passed += 1
            log_success(f"[PASS] {tc_name}")
        else:
            failed += 1
            failed_cases.append(tc_name)
            log_error(f"[FAIL] {tc_name}")

        time.sleep(1)

    log_info(f"\n{'='*60}")
    log_info(
        f"Suite Summary: {passed} passed, {failed} failed, {skipped} skipped"
    )
    if skipped_cases:
        log_warning(f"Skipped cases: {skipped_cases}")
    if failed_cases:
        log_error(f"Failed cases: {failed_cases}")
    log_info(f"{'='*60}")

    return failed == 0


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Run HDMI CEC test suites")
    parser.add_argument(
        "suite",
        help=f"Test suite name. Available: {list(SUITES.keys())}",
    )
    parser.add_argument(
        "-t",
        "--timing",
        action="store_true",
        help="Enable timing output for passed test cases",
    )
    parser.add_argument(
        "--test",
        dest="tests",
        action="append",
        help="Run only the named testcase module. Repeat to run multiple specific tests.",
    )

    args = parser.parse_args()

    if args.timing:
        os.environ["HDMICEC_TIMING_ENABLED"] = "1"

    suite_arg = normalize_suite_name(args.suite)
    matching = [
        key for key in SUITES if normalize_suite_name(key) == suite_arg
    ]
    if not matching:
        log_error(
            f"Unknown suite '{args.suite}'. Available: {list(SUITES.keys())}"
        )
        sys.exit(1)

    try:
        ok = run_suite(matching[0], args.tests)
    except (ValueError, AttributeError) as exc:
        log_error(str(exc))
        sys.exit(1)
    sys.exit(0 if ok else 1)
