#ifndef BASE_CT_WRAPPER_H
#define BASE_CT_WRAPPER_H

#include <crpdfcpp/wrapper/point_wrapper.h>
#include <crpdfcpp/wrapper/limit_wrapper.h>
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