#pragma once

namespace ParamArgs
{
    class Limit
    {
    private:
        /* data */
        double width, height;

    public:
        Limit(/* args */) = default;
        Limit(double _width, double _height);
        ~Limit();

        void set_width(double _width);
        void set_height(double _height);

        double get_width();
        double get_height();
    };

}