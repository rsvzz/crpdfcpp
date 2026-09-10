#include <crpdfcpp/wrapper/limit_wrapper.h>
#include <crpdfcpp/limit.hpp>
#include <iostream>

using namespace ParamArgs;

extern "C"
{
    double limit_get_width(LimitHandle *ptr)
    {
        if (ptr == nullptr)
            return 0.0; // null

        Limit *limit = reinterpret_cast<Limit *>(ptr);
        return limit->get_width();
    }

    double limit_get_height(LimitHandle *ptr)
    {
        if (ptr == nullptr)
            return 0.0; // null

        Limit *limit = reinterpret_cast<Limit *>(ptr);
        return limit->get_height();
    }
}
