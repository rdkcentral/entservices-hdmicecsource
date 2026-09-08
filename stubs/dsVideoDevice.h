#pragma once

#include "dsVideoPort.h"
#include "dsVideoDeviceTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*dsVideoDeviceFramerateCallback_t)(char*);

dsError_t dsVideoDeviceInit(void);
dsError_t dsVideoDeviceTerm(void);
dsError_t dsGetVideoDevice(int, intptr_t*);
dsError_t dsSetDFC(intptr_t, dsVideoZoom_t);
dsError_t dsGetHDRCapabilities(intptr_t, int*);
dsError_t dsGetSupportedVideoCodingFormats(intptr_t, unsigned int*);
dsError_t dsGetVideoCodecInfo(intptr_t, dsVideoCodingFormat_t, dsVideoCodecInfo_t*);
dsError_t dsForceDisableHDRSupport(intptr_t, bool);
dsError_t dsSetFRFMode(intptr_t, int);
dsError_t dsGetFRFMode(intptr_t, int*);
dsError_t dsGetCurrentDisplayframerate(intptr_t, char*);
dsError_t dsSetDisplayframerate(intptr_t, char*);
dsError_t VideoDeviceRegisterFrameratePreChangeCB(dsVideoDeviceFramerateCallback_t);
dsError_t VideoDeviceRegisterFrameratePostChangeCB(dsVideoDeviceFramerateCallback_t);
dsError_t dsHdmiInSelectZoomMode(dsVideoZoom_t);

#ifdef __cplusplus
}
#endif
