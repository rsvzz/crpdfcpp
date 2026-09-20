#include "text.hpp"
#include <cairo/cairo-pdf.h>

using namespace Controls;
using namespace ParamArgs;

Text::Text(string _label, string f_family, double f_size, cairo_font_slant_t f_slant, cairo_font_weight_t f_weight, double w, double h, double x, double y) : BaseCT(w, h, x, y)
{
    label = _label;
    font_family = f_family;
    font_size = f_size;
    font_slant = f_slant;
    font_weight = f_weight;
}

Text::~Text() {}

void Text::draw(cairo_t *ctx)
{
    cairo_select_font_face(ctx, this->font_family.c_str(), font_slant, font_weight);
    cairo_set_font_size(ctx, this->font_size);
    cairo_set_source_rgb(ctx, 0.0, 0.0, 0.0); // Color negro
    cairo_move_to(ctx, this->x, this->y);              // Posición (x, y)
    cairo_show_text(ctx, this->label.c_str());
}

const string &Text::get_label() { return label; }