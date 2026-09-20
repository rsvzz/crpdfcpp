#ifndef CREATE_PDF_WRAPPER_H
#define CREATE_PDF_WRAPPER_H

#include <cairo/cairo.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef struct crpdf_handle CrPdfHandel;
/// @brief Create obj CreatePDF
/// @param  FilePath
/// @param  width 
/// @param  height
/// @return Create Surface
CrPdfHandel* crpdf_create(const char*, double, double);

cairo_t* crpdf_get_context(CrPdfHandel*);
void crpdf_free(CrPdfHandel*);
/// @brief cairo_t* and cairo_surface_t* free memory
/// @param  
void crpdf_cairo_surface_free(CrPdfHandel*);

#ifdef __cplusplus
}
#endif

#endif