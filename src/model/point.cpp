#include <crpdfcpp/point.hpp>
using namespace ParamArgs;

Point::Point(double _x, double _y){
    x = _x;
    y = _y;
}

Point::~Point(){
}

void Point::set_x(double _x){
    x = _x;
}

void Point::set_y(double _y){
    y = _y;
}

double Point::get_x(){
    return x;
}

double Point::get_y(){
    return y;
}
