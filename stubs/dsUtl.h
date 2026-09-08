#pragma once

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum dsUtlStatus {
    dsUTL_SUCCESS = 0,
    dsUTL_ERROR = -1
} dsUtlStatus_t;

#define DSUTL_MAX_STRING_LENGTH 256

static inline int dsUtlIsNullOrEmpty(const char* value)
{
    return (value == NULL) || (value[0] == '\0');
}

static inline int dsUtlIsValidString(const char* value)
{
    return (value != NULL) && (value[0] != '\0');
}

#ifdef __cplusplus
}
#endif
