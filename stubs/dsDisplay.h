#pragma once

#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	dsDISPLAY_EVENT_CONNECTED = 0,
	dsDISPLAY_EVENT_DISCONNECTED,
	dsDISPLAY_RXSENSE_ON,
	dsDISPLAY_RXSENSE_OFF,
	dsDISPLAY_HDCPPROTOCOL_CHANGE,
	dsDISPLAY_EVENT_MAX
} dsDisplayEvent_t;

typedef enum {
	dsAVICONTENT_TYPE_NOT_SIGNALLED = 0,
	dsAVICONTENT_TYPE_GRAPHICS,
	dsAVICONTENT_TYPE_PHOTO,
	dsAVICONTENT_TYPE_CINEMA,
	dsAVICONTENT_TYPE_GAME
} dsAviContentType_t;

typedef enum {
	dsAVI_SCAN_TYPE_NO_DATA = 0,
	dsAVI_SCAN_TYPE_OVERSCAN,
	dsAVI_SCAN_TYPE_UNDERSCAN
} dsAVIScanInformation_t;

typedef struct {
	uint16_t productCode;
	uint32_t serialNumber;
	uint16_t manufactureYear;
	uint8_t manufactureWeek;
	char monitorName[64];
	bool hdmiDeviceType;
	bool isRepeater;
	uint8_t physicalAddressA;
	uint8_t physicalAddressB;
	uint8_t physicalAddressC;
	uint8_t physicalAddressD;
	uint8_t numOfSupportedResolution;
} dsDisplayEDID_t;

typedef void (*dsDisplayEventCallback_t)(int, dsDisplayEvent_t, void*);

dsError_t dsDisplayInit(void);
dsError_t dsDisplayTerm(void);
dsError_t dsIsDisplayConnected(intptr_t, bool*);
dsError_t dsGetDisplaySurroundMode(intptr_t, int*);
dsError_t dsGetEDIDBytes(intptr_t, unsigned char*, int*);
dsError_t dsGetDisplay(dsVideoPortType_t, int, intptr_t*);
dsError_t dsGetDisplayAspectRatio(intptr_t, dsVideoAspectRatio_t*);
dsError_t dsGetEDID(intptr_t, dsDisplayEDID_t*);
dsError_t dsRegisterDisplayEventCallback(intptr_t, dsDisplayEventCallback_t);

#ifdef __cplusplus
}
#endif

