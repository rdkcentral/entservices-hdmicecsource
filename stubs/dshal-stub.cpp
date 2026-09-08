// DeviceSettings HAL stub implementation for vdevice
// Provides minimal C API implementations used by vdevice builds/runtime.

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STUB(name) int name() { return 0; }

STUB(dsDisplayInit)
STUB(dsDisplayTerm)
STUB(dsIsDisplayConnected)
STUB(dsGetDisplaySurroundMode)
STUB(dsGetEDIDBytes)

int dsGetDisplay(int, int, void** handle) {
    static int dummy_handle = 0;
    if (handle) {
        *handle = &dummy_handle;
    }
    return 0;
}

STUB(dsGetDisplayAspectRatio)

int dsGetEDID(void*, unsigned char* edid, int* length) {
    if (edid && length && *length >= 256) {
        memset(edid, 0, 256);
        *length = 256;
        return 0;
    }
    return -1;
}

STUB(dsSetAllmEnabled)
STUB(dsGetAllmEnabled)
STUB(dsSetAVIContentType)
STUB(dsGetAVIContentType)
STUB(dsSetAVIScanInformation)
STUB(dsGetAVIScanInformation)
STUB(dsRegisterDisplayEventCallback)

STUB(dsFPInit)
STUB(dsFPTerm)
STUB(dsSetFPBrightness)
STUB(dsGetFPBrightness)
STUB(dsGetFPColor)
STUB(dsSetFPColor)
STUB(dsSetFPDMode)
int dsFPDColor_isValid() { return 1; }

STUB(dsHostInit)
STUB(dsHostTerm)
STUB(dsGetHostEDID)

STUB(dsVideoDeviceInit)
STUB(dsVideoDeviceTerm)
STUB(dsGetVideoDevice)
STUB(dsSetDFC)
STUB(dsGetHDRCapabilities)
STUB(dsGetSupportedVideoCodingFormats)
STUB(dsGetVideoCodecInfo)
STUB(dsForceDisableHDRSupport)
STUB(dsSetFRFMode)
STUB(dsGetFRFMode)
STUB(dsGetCurrentDisplayframerate)
STUB(dsSetDisplayframerate)
STUB(dsRegisterFrameratePreChangeCB)
STUB(dsRegisterFrameratePostChangeCB)
STUB(dsHdmiInSelectZoomMode)

STUB(dsVideoPortInit)
STUB(dsVideoPortTerm)
STUB(dsGetVideoPort)
STUB(dsIsVideoPortEnabled)
STUB(dsEnableVideoPort)
STUB(dsIsVideoPortActive)
STUB(dsGetResolution)
STUB(dsGetColorDepth)
STUB(dsSetPreferredColorDepth)
STUB(dsGetQuantizationRange)
STUB(dsGetColorSpace)
STUB(dsGetHDCPStatus)
STUB(dsGetHDCPProtocol)
STUB(dsGetHDCPReceiverProtocol)
STUB(dsGetHDCPCurrentProtocol)
STUB(dsGetVideoEOTF)
STUB(dsGetMatrixCoefficients)
STUB(dsIsDisplaySurround)
STUB(dsGetSurroundMode)
STUB(dsGetCurrentOutputSettings)
STUB(dsGetPreferredColorDepth)
STUB(dsSetResolution)
STUB(dsEnableHDCP)
STUB(dsIsHDCPEnabled)
STUB(dsGetTVHDRCapabilities)
STUB(dsSupportedTvResolutions)
STUB(dsSetForceDisable4KSupport)
STUB(dsGetForceDisable4KSupport)
STUB(dsIsOutputHDR)
STUB(dsResetOutputToSDR)
STUB(dsGetHdmiPreference)
STUB(dsSetHdmiPreference)
STUB(dsSetBackgroundColor)
STUB(dsSetForceHDRMode)
STUB(dsColorDepthCapabilities)
STUB(dsRegisterHdcpStatusCallback)
STUB(dsVideoFormatUpdateRegisterCB)

STUB(dsCompositeInInit)
STUB(dsCompositeInTerm)
STUB(dsCompositeInGetNumberOfInputs)
STUB(dsCompositeInGetStatus)
STUB(dsCompositeInSelectPort)
STUB(dsCompositeInScaleVideo)
STUB(dsCompositeInRegisterConnectCB)
STUB(dsCompositeInRegisterSignalChangeCB)
STUB(dsCompositeInRegisterStatusChangeCB)
STUB(dsCompositeInRegisterVideoModeUpdateCB)

STUB(dsAudioOutRegisterConnectCB)
STUB(dsAudioFormatUpdateRegisterCB)
STUB(dsAudioAtmosCapsChangeRegisterCB)
STUB(dsAudioPortInit)
STUB(dsAudioPortTerm)
STUB(dsGetAudioPort)
STUB(dsGetAudioCapabilities)
STUB(dsGetMS12Capabilities)
STUB(dsGetAudioFormat)
STUB(dsGetStereoMode)
STUB(dsGetAudioCompression)
STUB(dsSetAudioCompression)
STUB(dsGetAudioLevel)
STUB(dsSetAudioLevel)
STUB(dsSetAudioGain)
STUB(dsGetAudioGain)
STUB(dsSetAudioMute)
STUB(dsIsAudioMute)
STUB(dsIsAudioPortEnabled)
STUB(dsSetStereoMode)
STUB(dsSetAssociatedAudioMixing)
STUB(dsGetAssociatedAudioMixing)
STUB(dsSetFaderControl)
STUB(dsGetFaderControl)
STUB(dsSetPrimaryLanguage)
STUB(dsGetPrimaryLanguage)
STUB(dsSetSecondaryLanguage)
STUB(dsGetSecondaryLanguage)
STUB(dsAudioOutIsConnected)
STUB(dsGetSinkDeviceAtmosCapability)
STUB(dsSetAudioAtmosOutputMode)
STUB(dsEnableAudioPort)
STUB(dsGetSupportedARCTypes)
STUB(dsAudioSetSAD)
STUB(dsAudioEnableARC)
STUB(dsIsAudioMSDecode)
STUB(dsIsAudioMS12Decode)
STUB(dsGetLEConfig)
STUB(dsEnableLEConfig)
STUB(dsSetAudioDelay)
STUB(dsGetAudioDelay)
STUB(dsSetAudioDelayOffset)
STUB(dsGetAudioDelayOffset)
STUB(dsSetDialogEnhancement)
STUB(dsGetDialogEnhancement)
STUB(dsSetDolbyVolumeMode)
STUB(dsGetDolbyVolumeMode)
STUB(dsSetIntelligentEqualizerMode)
STUB(dsGetIntelligentEqualizerMode)
STUB(dsSetVolumeLeveller)
STUB(dsGetVolumeLeveller)
STUB(dsSetBassEnhancer)
STUB(dsGetBassEnhancer)
STUB(dsEnableSurroundDecoder)
STUB(dsIsSurroundDecoderEnabled)
STUB(dsSetDRCMode)
STUB(dsGetDRCMode)
STUB(dsSetSurroundVirtualizer)
STUB(dsGetSurroundVirtualizer)
STUB(dsSetMISteering)
STUB(dsGetMISteering)
STUB(dsSetGraphicEqualizerMode)
STUB(dsGetGraphicEqualizerMode)
STUB(dsGetMS12AudioProfileList)
STUB(dsGetMS12AudioProfile)
STUB(dsSetMS12AudioProfile)
STUB(dsSetMixerLevel)
STUB(dsSetStereoAuto)
STUB(dsGetStereoAuto)

#ifdef __cplusplus
}
#endif
