#ifndef LINE_WRAPPER_H
#define LINE_WRAPPER_H

#include "base_ct.h"
#include "object_enum.h"
#include <cairo/cairo.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct linehandle LineHandle;

    /// @brief Get LineHandle
    /// @param stickness double
    /// @param orientation 
    /// @param w width
    /// @param h height
    /// @param x (x, y) 
    /// @param y (x, y)
    /// @return 
    LineHandle *line_create(double stickness, Axis orientation, double w, double h, double x, double y);
    /// @brief 
    /// @param ptr *
    /// @param cairo_t*
    void line_draw(LineHandle*, cairo_t*);

    BaseHandle* line_get_base(LineHandle*);
    
    /// @brief Free *ptr
    /// @param  LineHandle*
    void line_free(LineHandle *);
    
#ifdef __cplusplus
}
#endif

#endif