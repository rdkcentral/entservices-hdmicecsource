---
applyTo: "**/Module.cpp,**/Module.h"
---


### Module Name Convention

### Requirement

- Every plugin must define MODULE_NAME because Thunder uses MODULE_NAME to identify each plugin.
- Every plugin must also define the MODULE_NAME_DECLARATION() macro, which generates identifiers such as the module name string, SHA value, and version for the module, enabling the system to recognize and link it.
- The MODULE_NAME should start with the prefix Plugin_ for plugin modules, or ClientLibrary_ for client library modules.

### Example

1. Plugin module in Module.h:

   ```cpp
   // Rest of the code
   #ifndef MODULE_NAME
   #define MODULE_NAME Plugin_IOController
   #endif
   // Rest of the code
   ```

2. Client library module in Module.h:

   ```cpp
   // Rest of the code
   #ifndef MODULE_NAME
   #define MODULE_NAME ClientLibrary_PowerManager
   #endif
   // Rest of the code
   ```

3. In Module.cpp:

   ```cpp
   #include "Module.h"

   MODULE_NAME_DECLARATION(BUILD_REFERENCE)

   // Rest of the code
   ```