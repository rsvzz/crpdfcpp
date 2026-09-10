#pragma once
#include <string>
#include <cairo/cairo.h>

using namespace std;

namespace controls
{

    class CreatePDF
    {
    private:
        /* data */
        string path;
        cairo_surface_t *surface;
        cairo_t *ctx;
        double width, height;

    public:
        CreatePDF(string _path, double _width, double _height);
        ~CreatePDF();
    };

}