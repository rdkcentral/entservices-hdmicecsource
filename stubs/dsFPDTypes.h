#pragma once

typedef int dsFPDBrightness_t;
typedef int dsFPDState_t;
typedef int dsFPDColor_t;
typedef int dsFPDIndicator_t;

enum {
    dsFPD_INDICATOR_MESSAGE = 0,
    dsFPD_INDICATOR_POWER,
    dsFPD_INDICATOR_MAX
};

enum {
    dsFPD_BRIGHTNESS_MIN = 0,
    dsFPD_BRIGHTNESS_MAX = 100
};

enum {
    dsFPD_STATE_OFF = 0,
    dsFPD_STATE_ON
};

enum {
    dsFPD_COLOR_BLUE = 0,
    dsFPD_COLOR_GREEN,
    dsFPD_COLOR_RED,
    dsFPD_COLOR_YELLOW,
    dsFPD_COLOR_ORANGE
};
