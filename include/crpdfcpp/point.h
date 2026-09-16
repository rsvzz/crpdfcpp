#ifndef POINT_WRAPPER_H
#define POINT_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct pointhandle PointHandle;
/// @brief Get (x, y) 
/// @param  obj*
/// @return double x
double point_get_x(PointHandle*);
/// @brief Get (x, y)
/// @param  obj*
/// @return double y
double point_get_y(PointHandle*);
#ifdef __cplusplus
}
#endif

#endif