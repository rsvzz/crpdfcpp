#include <crpdfcpp/controls/text.hpp>
#include <cairo/cairo-pdf.h>

using namespace controls;

Text::Text(string _label, double w, double h, double x, double y): Limit(w, h), Point(x, y){
    label = _label;
}

Text::~Text(){}

void Text::draw(cairo_t *ctx){
}

const string& Text::get_label(){ return label;}