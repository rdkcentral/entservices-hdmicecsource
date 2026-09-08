#pragma once

#include "dsTypes.h"

typedef enum {
    dsVIDEO_ZOOM_NONE = 0,
    dsVIDEO_ZOOM_FULL,
    dsVIDEO_ZOOM_16_9_ZOOM,
    dsVIDEO_ZOOM_LB_16_9,
    dsVIDEO_ZOOM_LB_14_9,
    dsVIDEO_ZOOM_CCO,
    dsVIDEO_ZOOM_PAN_SCAN,
    dsVIDEO_ZOOM_LB_2_21_1_ON_4_3,
    dsVIDEO_ZOOM_LB_2_21_1_ON_16_9,
    dsVIDEO_ZOOM_PLATFORM,
    dsVIDEO_ZOOM_PILLARBOX_4_3,
    dsVIDEO_ZOOM_WIDE_4_3
} dsVideoZoom_t;

typedef enum {
    dsVIDEO_CODEC_UNKNOWN = 0,
    dsVIDEO_CODEC_MPEG2,
    dsVIDEO_CODEC_MPEGHPART2,
    dsVIDEO_CODEC_MPEG4PART10,
    dsVIDEO_CODEC_H265,
    dsVIDEO_CODEC_VP9,
    dsVIDEO_CODEC_AV1
} dsVideoCodingFormat_t;

typedef struct {
    uint32_t profiles;
    uint32_t levels;
} dsVideoCodecInfo_t;
