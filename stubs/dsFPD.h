#pragma once

#include "dsError.h"
#include "dsFPDTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

dsError_t dsFPInit(void);
dsError_t dsFPTerm(void);
dsError_t dsSetFPBrightness(dsFPDIndicator_t, dsFPDBrightness_t);
dsError_t dsGetFPBrightness(dsFPDIndicator_t, dsFPDBrightness_t*);
dsError_t dsGetFPColor(dsFPDIndicator_t, dsFPDColor_t*);
dsError_t dsSetFPColor(dsFPDIndicator_t, dsFPDColor_t);

#ifdef __cplusplus
}
#endif
