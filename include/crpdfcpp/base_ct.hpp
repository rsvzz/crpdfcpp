#pragma once
#include <crpdfcpp/point.hpp>
#include <crpdfcpp/limit.hpp>

using namespace ParamArgs;

namespace ParamArgs
{
    /// @brief class base for controls Point and Limit
    class BaseCT : public Point, public Limit
    {
    private:
        /* data */
    public:
        BaseCT(double w, double h, double x, double y);
        ~BaseCT(){};
    };
}
