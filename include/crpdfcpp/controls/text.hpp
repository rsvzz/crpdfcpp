#pragma once
#include <crpdfcpp/point.hpp>
#include <crpdfcpp/limit.hpp>
#include <crpdfcpp/controls/draw_pdf.hpp>

#include <string>
using namespace std;
using namespace ParamArgs;

namespace controls
{

    class Text : public Point, public Limit, public DrawPdf
    {
    private:
        /* data */
        string label;

    public:
        Text(string _label, double w, double h, double x, double y);
        ~Text();

        const string& get_label();

        void draw(cairo_t*) override;
    };

}