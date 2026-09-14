#ifndef LIMIT_WRAPPER_H
#define LIMIT_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct limithandle LimitHandle;
/// @brief Get (width, height) 
/// @param  obj*
/// @return double width
double limit_get_width(LimitHandle*);
/// @brief Get (width, height) 
/// @param  obj*
/// @return double height
double limit_get_height(LimitHandle*);
#ifdef __cplusplus
}
#endif

#endif