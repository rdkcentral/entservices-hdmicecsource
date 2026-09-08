#pragma once

#include "dsError.h"
#include "dsHdmiInTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*dsHdmiInConnectCB_t)(dsHdmiInPort_t, bool);
typedef void (*dsHdmiInSignalChangeCB_t)(dsHdmiInPort_t, dsHdmiInSignalStatus_t);
typedef void (*dsHdmiInStatusChangeCB_t)(dsHdmiInStatus_t);
typedef void (*dsHdmiInVideoModeUpdateCB_t)(dsHdmiInPort_t, dsVideoPortResolution_t);
typedef void (*dsHdmiInAllmChangeCB_t)(dsHdmiInPort_t, bool);
typedef void (*dsHdmiInAviContentTypeChangeCB_t)(dsHdmiInPort_t, dsAviContentType_t);
typedef void (*dsAVLatencyChangeCB_t)(int32_t, int32_t);
typedef void (*dsHdmiInVRRChangeCB_t)(dsHdmiInPort_t, dsVRRType_t);

dsError_t dsHdmiInInit(void);
dsError_t dsHdmiInTerm(void);
dsError_t dsHdmiInRegisterConnectCB(dsHdmiInConnectCB_t);
dsError_t dsHdmiInRegisterSignalChangeCB(dsHdmiInSignalChangeCB_t);
dsError_t dsHdmiInRegisterStatusChangeCB(dsHdmiInStatusChangeCB_t);
dsError_t dsHdmiInRegisterVideoModeUpdateCB(dsHdmiInVideoModeUpdateCB_t);
dsError_t dsHdmiInRegisterAllmChangeCB(dsHdmiInAllmChangeCB_t);
dsError_t dsHdmiInRegisterAviContentTypeChangeCB(dsHdmiInAviContentTypeChangeCB_t);
dsError_t dsHdmiInRegisterAVLatencyChangeCB(dsAVLatencyChangeCB_t);
dsError_t dsHdmiInRegisterVRRChangeCB(dsHdmiInVRRChangeCB_t);
dsError_t dsHdmiInGetNumberOfInputs(uint8_t*);
dsError_t dsHdmiInGetStatus(dsHdmiInStatus_t*);
dsError_t dsHdmiInSelectPort(dsHdmiInPort_t, bool, dsVideoPlaneType_t, bool);
dsError_t dsHdmiInScaleVideo(int, int, int, int);
dsError_t dsHdmiInSelectZoomMode(dsVideoZoom_t);
dsError_t dsHdmiInGetCurrentVideoMode(dsVideoPortResolution_t*);
dsError_t dsHdmiInGetVRRSupport(dsHdmiInPort_t, bool*);
dsError_t dsHdmiInSetVRRSupport(dsHdmiInPort_t, bool);
dsError_t dsSetEdid2AllmSupport(dsHdmiInPort_t, bool);
bool dsIsHdmiARCPort(int, bool*);
dsError_t dsSetEdidVersion(dsHdmiInPort_t, tv_hdmi_edid_version_t);
dsError_t dsGetEdidVersion(dsHdmiInPort_t, tv_hdmi_edid_version_t*);
dsError_t dsGetAllmStatus(dsHdmiInPort_t, bool*);
dsError_t dsGetSupportedGameFeaturesList(dsSupportedGameFeatureList_t*);
dsError_t dsGetAVLatency(int*, int*);
dsError_t dsGetHdmiVersion(dsHdmiInPort_t, dsHdmiMaxCapabilityVersion_t*);
dsError_t dsGetEDIDBytesInfo(dsHdmiInPort_t, unsigned char*, int*);
dsError_t dsGetHDMISPDInfo(dsHdmiInPort_t, unsigned char*);
dsError_t dsHdmiInGetVRRStatus(dsHdmiInPort_t, dsHdmiInVrrStatus_t*);

#ifdef __cplusplus
}
#endif
