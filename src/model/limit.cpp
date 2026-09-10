#include <crpdfcpp/limit.hpp>

using namespace ParamArgs;

Limit::Limit(double _w, double _h)
{
    this->width = _w;
    this->height = _h;
}

Limit::~Limit() {}

void Limit::set_width(double _w)
{
    this->width = _w;
}

void Limit::set_height(double _h)
{
    this->height = _h;
}

double Limit::get_width() { return this->width; }
double Limit::get_height() { return this->height; }
