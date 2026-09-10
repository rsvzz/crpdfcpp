#pragma once

namespace ParamArgs
{
    class Point
    {
    private:
        /* data */
        double x, y;

    public:
        Point(/* args */) = default;
        Point(double x, double y);
        ~Point();

        void set_x(double);
        void set_y(double);

        double get_x();
        double get_y();
    };

}
