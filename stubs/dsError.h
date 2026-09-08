#ifndef VDEVICE_NOOP_DSERROR_H
#define VDEVICE_NOOP_DSERROR_H

typedef int dsError_t;

static const dsError_t dsERR_NONE = 0;
static const dsError_t dsERR_GENERAL = 1;
static const dsError_t dsERR_INVALID_PARAM = 2;
static const dsError_t dsERR_OPERATION_NOT_SUPPORTED = 3;

#endif
