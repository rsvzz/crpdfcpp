#pragma once
#include <cairo/cairo.h>

namespace controls
{
    class DrawPdf
    {
    private:
        /* data */
    public:
        DrawPdf(/* args */) = default;
        ~DrawPdf(){}

        virtual void draw(cairo_t *ctx) = 0;
    };
}
