#include <iostream>
#include <crpdfcpp/wrapper/text_wrapper.h>
#include <crpdfcpp/wrapper/base_ct_wrapper.h>
#include <crpdfcpp/wrapper/point_wrapper.h>

// using namespace controls;

int main()
{
    TextHandle *tx = text_create("LABEL NAME", 100.0, 40.0, 50.0, 50.0);
    
    BaseHandle *base = text_get_base(tx);
    PointHandle *pt = base_get_point(base);
    LimitHandle *limit = base_get_limit(base);

    printf("label %s  (%f, %f) (%f, %f) \n", text_get_label(tx), limit_get_width(limit), limit_get_height(limit), point_get_x(pt), point_get_y(pt));
    text_free(tx);
    // printf("(%f, %f) and width = %f and height = %f \n", tx.get_x(), tx.get_y(), tx.get_width(), tx.get_height());

    // printf("sum : %f \n", cal_get_sum(10,10));
    // printf("res : %f otra: %f \n", cal_get_sum(20, 10), ss);

    return 0;
}