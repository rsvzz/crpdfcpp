#ifndef TEXT_WRAPPER_H
#define TEXT_WRAPPER_H

#include <crpdfcpp/wrapper/point_wrapper.h>
#include <crpdfcpp/wrapper/limit_wrapper.h>

#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct texthandle TextHandle;

    TextHandle *text_create(const char *, double w, double h, double x, double y);
    /// @brief get ptr for PointHandle of TextHandle
    /// @param
    /// @return PointHandle*
    PointHandle *text_get_point(TextHandle *);
    /// @brief get ptr for LimitHandle of TextHandle
    /// @param
    /// @return
    LimitHandle *text_get_limit(TextHandle *);
    const char *text_get_label(TextHandle *);
    /// @brief Free *ptr
    /// @param  LimitHandle*
    void text_free(TextHandle *);
#ifdef __cplusplus
}
#endif

#endif
