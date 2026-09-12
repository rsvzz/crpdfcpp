#pragma once
#include <crpdfcpp/base_ct.hpp>
#include <crpdfcpp/controls/draw_pdf.hpp>

#include <string>
using namespace std;
using namespace ParamArgs;

namespace Controls
{

    class Text : public BaseCT, public DrawPdf
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