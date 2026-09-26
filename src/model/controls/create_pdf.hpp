#pragma once
#include <string>
#include <cairo/cairo.h>

using namespace std;

namespace Controls
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

        cairo_t* get_context();
        cairo_surface_t* get_surface();
        void cairo_surface_free();
        void new_page_pdf();
    };

}