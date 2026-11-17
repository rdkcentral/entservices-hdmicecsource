To execute the cases inside qemu

cd /tmp

git clone git@github.com:rdkcentral/entservices-hdmicecsource.git

cd entservices-hdmicecsource/Tests/vDeviceTests

EXECUTION:
with time : python3 SuiteManager.py -t hdmicecsource
without time: python3 SuiteManager.py hdmicecsource
single test: python3 SuiteManager.py hdmicecsource --test TCID01_Send_Standby_Message
multiple tests: repeat --test for each required testcase

Default Actions:
Plugin lifecycle is per-test. Before every selected test, the plugin is
activated and Init_Devicelist_Populate is run. The plugin is deactivated after
that test, including setup or test failures:
- hdmicecsource -> Controller.1.activate(callsign=org.rdk.HdmiCecSource)
- Init_Devicelist_Populate -> test -> Controller.1.deactivate

Disable default activation only if needed:
- export AUTO_ACTIVATE_PLUGINS=0

Plugin activation is retried for up to 40 seconds. The post-activation wait
defaults to 6 seconds and can be changed with:
- export HDMICEC_PLUGIN_INIT_WAIT=<seconds>
- export PLUGIN_INIT_WAIT=<seconds> (shared fallback)


If the testcases fail with "connection refused", configure endpoint host/ports before running.

Defaults used by the tests:
- MW JSON-RPC: http://127.0.0.1:9998/jsonrpc
- vComponent API: http://127.0.0.1:8080/api/postKVP

Useful overrides:
- TARGET_HOST (applies to both endpoints)
- JSONRPC_PORT
- VCOMPONENT_PORT
- WPEFRAMEWORK_JSONRPC_URL (full URL, highest priority)
- VCOMPONENT_API_URL (full URL, highest priority)

Examples:

# when running directly inside QEMU guest (services on localhost)
python3 SuiteManager.py hdmicecsource

# when running from host against QEMU target IP
export TARGET_HOST=192.168.1.50
export JSONRPC_PORT=9998
export VCOMPONENT_PORT=8080
python3 SuiteManager.py hdmicecsource

# full URL override form
export WPEFRAMEWORK_JSONRPC_URL=http://192.168.1.50:9998/jsonrpc
export VCOMPONENT_API_URL=http://192.168.1.50:8080/api/postKVP
python3 SuiteManager.py hdmicecsource


Troubleshooting:
- If you see connection errors, verify WPEFramework JSON-RPC and the vComponent API are reachable using the endpoint overrides above.
