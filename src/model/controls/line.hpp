#pragma once
#include "../base_ct.hpp"
#include "../../../include/crpdfcpp/object_enum.h"
#include "draw_pdf.hpp"

#include <string>
using namespace std;
using namespace ParamArgs;

namespace Controls
{

    class Line : public BaseCT, public DrawPdf
    {
    private:
        /* data */
        double thickness;
        Axis orientation;

    public:
        Line(double _thickness, Axis _orientation, double w, double h, double x, double y);
        ~Line();
        void draw(cairo_t*) override;
    };
}
