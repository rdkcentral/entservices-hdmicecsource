import contextlib
import io
from pathlib import Path
import runpy
import sys
import unittest
from unittest import mock

import SuitManager


class SuiteHelpTests(unittest.TestCase):
    def test_help_lists_commands_and_registered_cases_without_running_tests(self):
        script = str(Path(SuitManager.__file__).resolve())
        for arguments in (["-h"], ["--help"], ["hdmicecsource", "--help"],
                          ["-t", "hdmicecsource", "--help"]):
            with self.subTest(arguments=arguments):
                output = io.StringIO()
                with mock.patch.object(sys, "argv", [script] + arguments), \
                        mock.patch("utils.send_jsonrpc_command") as send_command, \
                        mock.patch("time.sleep") as sleep, \
                        mock.patch.dict("os.environ", {}, clear=True), \
                        mock.patch("importlib.import_module") as import_module, \
                        contextlib.redirect_stdout(output):
                    with self.assertRaises(SystemExit) as exited:
                        runpy.run_path(script, run_name="__main__")

                self.assertEqual(exited.exception.code, 0)
                import_module.assert_not_called()
                send_command.assert_not_called()
                sleep.assert_not_called()
                help_text = output.getvalue()
                self.assertIn("usage:", help_text)
                self.assertIn("-t, --timing", help_text)
                self.assertIn("Run all tests with timing", help_text)
                self.assertIn("No interactive prompts", help_text)
                self.assertIn("AUTO_ACTIVATE_PLUGINS", help_text)
                actual_cases = [
                    line.strip() for line in help_text.splitlines()
                    if line.strip().startswith("TCID")
                ]
                expected_cases = [
                    f"{test_id}: {description.replace('_', ' ')}"
                    for config in SuitManager.SUITES.values()
                    for test_id, description in (
                        name.split("_", 1) for name in config["tests"]
                    )
                ]
                self.assertEqual(actual_cases, expected_cases)


if __name__ == "__main__":
    unittest.main()
