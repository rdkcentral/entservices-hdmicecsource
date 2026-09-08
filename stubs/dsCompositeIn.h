#pragma once

#include "dsDisplay.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int dsCompositeInPort_t;

typedef struct {
    dsCompositeInPort_t activePort;
    bool isPresented;
} dsCompositeInStatus_t;

dsError_t dsCompositeInInit(void);
dsError_t dsCompositeInTerm(void);
dsError_t dsCompositeInGetNumberOfInputs(uint8_t*);
dsError_t dsCompositeInGetStatus(dsCompositeInStatus_t*);
dsError_t dsCompositeInSelectPort(dsCompositeInPort_t);
dsError_t dsCompositeInScaleVideo(int, int, int, int);

#ifdef __cplusplus
}
#endif
