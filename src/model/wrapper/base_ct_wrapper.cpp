#include <crpdfcpp/wrapper/base_ct_wrapper.h>
#include <crpdfcpp/base_ct.hpp>

extern "C"
{
    PointHandle *base_get_point(BaseHandle *ptr)
    {
        if (ptr == nullptr)
            return nullptr; // null

        Point *pt = reinterpret_cast<BaseCT *>(ptr);
        return reinterpret_cast<PointHandle *>(pt);
    }

    LimitHandle *base_get_limit(BaseHandle *ptr)
    {
         if (ptr == nullptr)
            return nullptr; // null

        Limit *pt = reinterpret_cast<BaseCT *>(ptr);
        return reinterpret_cast<LimitHandle *>(pt);
    }
}