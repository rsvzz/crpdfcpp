#ifndef TEXT_WRAPPER_H
#define TEXT_WRAPPER_H

#include "base_ct.h"
#include <cairo/cairo.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef enum font_slant{
        FONT_SLANT_NORMAL,
        FONT_SLANT_ITALIC,
        FONT_SLANT_OBLIQUE
    } FontSlant;


    typedef struct texthandle TextHandle;
    /// @brief new obj
    /// @param label_name show
    /// @param font family
    /// @param font slant
    /// @param font weight
    /// @param font size
    /// @param w width
    /// @param h height
    /// @param x (x,)
    /// @param y ( , y)
    /// @return TextHandle*
    TextHandle *text_create(const char *,const char*, double, cairo_font_slant_t, cairo_font_weight_t, double w, double h, double x, double y);
    /// @brief 
    /// @param  
    /// @param  
    void text_draw(TextHandle*, cairo_t*);

    BaseHandle* text_get_base(TextHandle*);
    
    const char *text_get_label(TextHandle *);
    /// @brief Free *ptr
    /// @param  LimitHandle*
    void text_free(TextHandle *);
#ifdef __cplusplus
}
#endif

#endif
