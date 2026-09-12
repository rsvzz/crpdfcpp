#include <crpdfcpp/controls/text.hpp>
#include <cairo/cairo-pdf.h>

using namespace Controls;
using namespace ParamArgs;

Text::Text(string _label, double w, double h, double x, double y): BaseCT(w, h, x, y){
    label = _label;
}

Text::~Text(){}

void Text::draw(cairo_t *ctx){
}

const string& Text::get_label(){ return label;}