#ifndef _DS_TYPES_H_
#define _DS_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum {
	dsVIDEOPORT_TYPE_HDMI = 0,
	dsVIDEOPORT_TYPE_INTERNAL,
	dsVIDEOPORT_TYPE_COMPONENT,
	dsVIDEOPORT_TYPE_COMPOSITE,
	dsVIDEOPORT_TYPE_RF,
	dsVIDEOPORT_TYPE_MAX
} dsVideoPortType_t;

typedef enum {
	dsVIDEO_ASPECT_RATIO_4x3 = 0,
	dsVIDEO_ASPECT_RATIO_16x9
} dsVideoAspectRatio_t;

typedef enum {
	dsVIDEO_FRAMERATE_UNKNOWN = 0,
	dsVIDEO_FRAMERATE_24,
	dsVIDEO_FRAMERATE_25,
	dsVIDEO_FRAMERATE_30,
	dsVIDEO_FRAMERATE_50,
	dsVIDEO_FRAMERATE_60,
	dsVIDEO_FRAMERATE_23dot98,
	dsVIDEO_FRAMERATE_29dot97,
	dsVIDEO_FRAMERATE_59dot94
} dsVideoFrameRate_t;

typedef enum {
	dsVIDEO_PIXELRES_UNKNOWN = 0,
	dsVIDEO_PIXELRES_720x480,
	dsVIDEO_PIXELRES_720x576,
	dsVIDEO_PIXELRES_1280x720,
	dsVIDEO_PIXELRES_1920x1080,
	dsVIDEO_PIXELRES_3840x2160,
	dsVIDEO_PIXELRES_4096x2160
} dsVideoPixelResolution_t;

typedef struct {
	char name[64];
	dsVideoPixelResolution_t pixelResolution;
	dsVideoFrameRate_t frameRate;
	bool interlaced;
	dsVideoAspectRatio_t aspectRatio;
	int stereoScopicMode;
} dsVideoPortResolution_t;

#endif /* _DS_TYPES_H_ */
