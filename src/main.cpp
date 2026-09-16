#include <iostream>
#include <crpdfcpp/text.h>
#include <crpdfcpp/base_ct.h>
#include <crpdfcpp/point.h>
#include <crpdfcpp/create_pdf.h>

// using namespace controls;

int main()
{
    CrPdfHandel *crpdf = crpdf_create("crpdf.pdf", 599.0, 800.0);
    
    TextHandle *tx = text_create("LABEL NAME", "Sans", 14.0, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD, 100.0, 40.0, 50.0, 50.0);
    
    BaseHandle *base = text_get_base(tx);
    PointHandle *pt = base_get_point(base);
    LimitHandle *limit = base_get_limit(base);

    printf("label %s  (%f, %f) (%f, %f) \n", text_get_label(tx), limit_get_width(limit), limit_get_height(limit), point_get_x(pt), point_get_y(pt));
    cairo_t *cr = crpdf_get_context(crpdf);
    text_draw(tx, cr);
    text_free(tx);
    crpdf_free(crpdf);
    // printf("(%f, %f) and width = %f and height = %f \n", tx.get_x(), tx.get_y(), tx.get_width(), tx.get_height());

    // printf("sum : %f \n", cal_get_sum(10,10));
    // printf("res : %f otra: %f \n", cal_get_sum(20, 10), ss);

    return 0;
}