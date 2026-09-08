#pragma once

#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    dsAUDIOPORT_TYPE_ID_LR = 0,
    dsAUDIOPORT_TYPE_HDMI,
    dsAUDIOPORT_TYPE_SPDIF,
    dsAUDIOPORT_TYPE_SPEAKER,
    dsAUDIOPORT_TYPE_HDMI_ARC,
    dsAUDIOPORT_TYPE_HEADPHONE,
    dsAUDIOPORT_TYPE_MAX
} dsAudioPortType_t;

typedef enum {
    dsAUDIO_STEREO_UNKNOWN = 0,
    dsAUDIO_STEREO_MONO,
    dsAUDIO_STEREO_STEREO,
    dsAUDIO_STEREO_SURROUND,
    dsAUDIO_STEREO_PASSTHRU,
    dsAUDIO_STEREO_DD,
    dsAUDIO_STEREO_DDPLUS
} dsAudioStereoMode_t;

typedef int dsAudioFormat_t;
typedef int dsATMOSCapability_t;

enum {
    dsAUDIOSUPPORT_DD = 1 << 0,
    dsAUDIOSUPPORT_DDPLUS = 1 << 1
};

typedef void (*dsAudioOutConnectCallback_t)(dsAudioPortType_t, uint32_t, bool);
typedef void (*dsAudioFormatUpdateCallback_t)(dsAudioFormat_t);
typedef void (*dsAudioAtmosCapsChangeCallback_t)(dsATMOSCapability_t, bool);

dsError_t dsAudioPortInit(void);
dsError_t dsAudioPortTerm(void);
dsError_t dsGetAudioPort(dsAudioPortType_t, int, intptr_t*);
dsError_t dsGetAudioCapabilities(intptr_t, int*);
dsError_t dsGetMS12Capabilities(intptr_t, int*);
dsError_t dsGetAudioFormat(intptr_t, dsAudioFormat_t*);
dsError_t dsGetStereoMode(intptr_t, dsAudioStereoMode_t*);
dsError_t dsSetAudioMute(intptr_t, bool);
dsError_t dsAudioOutRegisterConnectCB(dsAudioOutConnectCallback_t);
dsError_t dsAudioFormatUpdateRegisterCB(dsAudioFormatUpdateCallback_t);
dsError_t dsAudioAtmosCapsChangeRegisterCB(dsAudioAtmosCapsChangeCallback_t);

#ifdef __cplusplus
}
#endif
