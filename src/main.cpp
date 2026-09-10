#include <iostream>
#include <crpdfcpp/wrapper/text_wrapper.h>

//using namespace controls;

int main(){
   TextHandle *tx = text_create("LABEL NAME", 100.0, 40.0, 50.0, 50.0);
    printf("label %s \n", text_get_label(tx));
    text_free(tx);
   //printf("(%f, %f) and width = %f and height = %f \n", tx.get_x(), tx.get_y(), tx.get_width(), tx.get_height());

    //printf("sum : %f \n", cal_get_sum(10,10));
    //printf("res : %f otra: %f \n", cal_get_sum(20, 10), ss);

    return 0;
}