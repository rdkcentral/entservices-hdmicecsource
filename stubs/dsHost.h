#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum dsHostEvent {
    dsHOST_EVENT_NONE = 0,
    dsHOST_EVENT_CONNECTED,
    dsHOST_EVENT_DISCONNECTED,
    dsHOST_EVENT_MAX
} dsHostEvent_t;

typedef struct dsHostInfo {
    uint32_t version;
    char name[64];
} dsHostInfo_t;

static inline int dsHostInit(void) { return 0; }
static inline int dsHostTerm(void) { return 0; }
static inline int dsGetHostEDID(void* handle, unsigned char* edid, int* length)
{
    (void)handle;
    (void)edid;
    (void)length;
    return 0;
}

#ifdef __cplusplus
}
#endif
