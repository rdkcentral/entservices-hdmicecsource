#pragma once

#include "dsError.h"

#ifdef __cplusplus
extern "C" {
#endif

dsError_t dsHostInit(void);
dsError_t dsHostTerm(void);
dsError_t dsGetHostEDID(unsigned char*, int*);

#ifdef __cplusplus
}
#endif
