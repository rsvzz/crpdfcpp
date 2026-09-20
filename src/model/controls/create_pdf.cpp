#include "create_pdf.hpp"
#include <cairo/cairo-pdf.h>
#include <string>
#include <iostream>

using namespace Controls;

CreatePDF::CreatePDF(string _pth, double w, double h) : path(_pth), width(w), height(h)
{
    surface = cairo_pdf_surface_create(path.c_str(), width, height);

    if (cairo_surface_status(surface) != CAIRO_STATUS_SUCCESS)
    {
        std::cout << "Error dont create surface" << std::endl;
    }
    else
    {
        ctx = cairo_create(surface);
        if (cairo_status(ctx) != CAIRO_STATUS_SUCCESS)
        {
            std::cout << " Error dont create cairo of surface" << std::endl;
            cairo_surface_destroy(surface);
        }
    }
}

CreatePDF::~CreatePDF()
{
}

cairo_t* CreatePDF::get_context(){
    return this->ctx;
}

cairo_surface_t* CreatePDF::get_surface(){
    return this->surface;
}

/// @brief free cairo_t* and cairo_surface_t*
void CreatePDF::cairo_surface_free(){
    cairo_destroy(this->ctx);
    cairo_surface_destroy(this->surface);
}