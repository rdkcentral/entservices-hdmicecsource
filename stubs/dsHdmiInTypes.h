#pragma once

#include "dsDisplay.h"
#include "dsVideoDeviceTypes.h"

typedef enum {
    dsHDMI_IN_PORT_NONE = -1,
    dsHDMI_IN_PORT_0 = 0,
    dsHDMI_IN_PORT_1,
    dsHDMI_IN_PORT_2,
    dsHDMI_IN_PORT_3,
    dsHDMI_IN_PORT_4,
    dsHDMI_IN_PORT_MAX
} dsHdmiInPort_t;

typedef enum {
    dsHDMI_IN_SIGNAL_STATUS_NOSIGNAL = 0,
    dsHDMI_IN_SIGNAL_STATUS_UNDERSAMPLED,
    dsHDMI_IN_SIGNAL_STATUS_ALLM
} dsHdmiInSignalStatus_t;

typedef enum {
    dsVIDEO_PLANE_MAIN = 0,
    dsVIDEO_PLANE_PIP
} dsVideoPlaneType_t;

typedef enum {
    HDMI_EDID_VER_14 = 0,
    HDMI_EDID_VER_20,
    HDMI_EDID_VER_MAX
} tv_hdmi_edid_version_t;

typedef enum {
    HDMI_COMPATIBILITY_VERSION_14 = 0,
    HDMI_COMPATIBILITY_VERSION_20,
    HDMI_COMPATIBILITY_VERSION_21
} dsHdmiMaxCapabilityVersion_t;

typedef enum {
    dsVRR_NONE = 0,
    dsVRR_HDMI_VRR,
    dsVRR_AMD_FREESYNC
} dsVRRType_t;

typedef struct {
    dsHdmiInPort_t activePort;
    bool isPresented;
    bool isPortConnected[dsHDMI_IN_PORT_MAX];
} dsHdmiInStatus_t;

typedef struct {
    dsVRRType_t vrrType;
    double vrrAmdfreesyncFramerate_Hz;
} dsHdmiInVrrStatus_t;

typedef struct {
    bool isPortArcCapable[dsHDMI_IN_PORT_MAX];
} dsHdmiInCap_t;

typedef struct {
    int gameFeatureCount;
    char gameFeatureList[256];
} dsSupportedGameFeatureList_t;

typedef struct {
    uint8_t data[28];
} dsSpd_infoframe_st;
