#pragma once

#include "dsDisplay.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    dsDISPLAY_COLORDEPTH_AUTO = 0,
    dsDISPLAY_COLORDEPTH_8BIT,
    dsDISPLAY_COLORDEPTH_10BIT,
    dsDISPLAY_COLORDEPTH_12BIT
} dsDisplayColorDepth_t;

typedef enum {
    dsDISPLAY_QUANTIZATIONRANGE_UNKNOWN = 0,
    dsDISPLAY_QUANTIZATIONRANGE_DEFAULT,
    dsDISPLAY_QUANTIZATIONRANGE_LIMITED,
    dsDISPLAY_QUANTIZATIONRANGE_FULL
} dsDisplayQuantizationRange_t;

typedef enum {
    dsDISPLAY_COLORSPACE_UNKNOWN = 0,
    dsDISPLAY_COLORSPACE_RGB,
    dsDISPLAY_COLORSPACE_YCbCr422,
    dsDISPLAY_COLORSPACE_YCbCr444,
    dsDISPLAY_COLORSPACE_YCbCr420
} dsDisplayColorSpace_t;

typedef enum {
    dsHDCP_STATUS_UNAUTHENTICATED = 0,
    dsHDCP_STATUS_AUTHENTICATED
} dsHdcpStatus_t;

typedef enum {
    dsHDCP_VERSION_1X = 0,
    dsHDCP_VERSION_2X,
    dsHDCP_VERSION_2_2
} dsHdcpProtocolVersion_t;

typedef enum {
    dsHDRSTANDARD_NONE = 0,
    dsHDRSTANDARD_HDR10,
    dsHDRSTANDARD_HLG,
    dsHDRSTANDARD_DolbyVision
} dsHDRStandard_t;

typedef enum {
    dsDISPLAY_MATRIXCOEFFICIENT_UNKNOWN = 0,
    dsDISPLAY_MATRIXCOEFFICIENT_BT_709,
    dsDISPLAY_MATRIXCOEFFICIENT_BT_2020_NCL
} dsDisplayMatrixCoefficients_t;

dsError_t dsVideoPortInit(void);
dsError_t dsVideoPortTerm(void);
dsError_t dsGetVideoPort(dsVideoPortType_t, int, intptr_t*);
dsError_t dsIsVideoPortEnabled(intptr_t, bool*);
dsError_t dsEnableVideoPort(intptr_t, bool);
dsError_t dsIsVideoPortActive(intptr_t, bool*);
dsError_t dsGetResolution(intptr_t, dsVideoPortResolution_t*);
dsError_t dsGetColorDepth(intptr_t, unsigned int*);
dsError_t dsSetPreferredColorDepth(intptr_t, dsDisplayColorDepth_t);
dsError_t dsGetQuantizationRange(intptr_t, dsDisplayQuantizationRange_t*);
dsError_t dsGetColorSpace(intptr_t, dsDisplayColorSpace_t*);
dsError_t dsGetHDCPStatus(intptr_t, dsHdcpStatus_t*);
dsError_t dsGetHDCPProtocol(intptr_t, dsHdcpProtocolVersion_t*);
dsError_t dsGetHDCPReceiverProtocol(intptr_t, dsHdcpProtocolVersion_t*);
dsError_t dsGetHDCPCurrentProtocol(intptr_t, dsHdcpProtocolVersion_t*);
dsError_t dsGetVideoEOTF(intptr_t, dsHDRStandard_t*);
dsError_t dsGetMatrixCoefficients(intptr_t, dsDisplayMatrixCoefficients_t*);

#ifdef __cplusplus
}
#endif
