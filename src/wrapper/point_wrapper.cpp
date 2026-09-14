#include "../../include/crpdfcpp/point_wrapper.h"
#include "../model/point.hpp"

#
using namespace ParamArgs;

extern "C"
{
    double point_get_x(PointHandle *ptr)
    {
        if (ptr == nullptr)
            return 0.0; // null

        Point *pt = reinterpret_cast<Point *>(ptr);
        return pt->get_x();
    }

    double point_get_y(PointHandle *ptr)
    {
        if (ptr == nullptr)
            return 0.0; // null

        Point *pt = reinterpret_cast<Point *>(ptr);
        return pt->get_y();
    }
}
