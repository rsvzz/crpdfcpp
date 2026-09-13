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
        string font_family;
        double font_size;
        cairo_font_slant_t font_slant;
        cairo_font_weight_t font_weight;
    public:
        /// @brief new obj
        /// @param _label
        /// @param f_family
        /// @param f_size  
        /// @param f_slant 
        /// @param f_weight 
        /// @param w width
        /// @param h height
        /// @param x axis x
        /// @param y axis y
        Text(string _label, string f_family, double f_size, cairo_font_slant_t f_slant, cairo_font_weight_t f_weight, double w, double h, double x, double y);
        ~Text();

        const string& get_label();

        void draw(cairo_t*) override;
    };

}