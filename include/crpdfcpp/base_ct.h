#ifndef BASE_CT_H
#define BASE_CT_H

#include "point.h"
#include "limit.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef struct base_handle BaseHandle;

PointHandle* base_get_point(BaseHandle*);
LimitHandle* base_get_limit(BaseHandle*);

#ifdef __cplusplus
}
#endif

#endif