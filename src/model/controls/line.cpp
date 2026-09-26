#include "line.hpp"
#include <cairo/cairo-pdf.h>

using namespace Controls;

Line::Line(double _stickless, Axis _orientation, double w, double h, double x, double y) : BaseCT(w, h, x, y)
{
    this->thickness = _stickless;
    this->orientation = _orientation;
}

Line::~Line() {}

void Line::draw(cairo_t *ctx)
{
    if (ctx != nullptr)
    {
        cairo_set_source_rgb(ctx, 0.0, 0.0, 0.0); // Color negro
        cairo_set_line_width(ctx, this->thickness);
        cairo_move_to(ctx, this->x, this->y); // Posición (x, y)

        if (this->orientation == HORIZONTAL_AXIS)
            cairo_line_to(ctx, this->get_width(), this->y);
        else
            cairo_line_to(ctx, this->x, this->get_height());
        
        cairo_stroke(ctx);
    }

}