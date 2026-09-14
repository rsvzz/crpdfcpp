#include "../../include/crpdfcpp/text_wrapper.h"
#include "../model/controls/text.hpp"
#include <string>

using namespace Controls;
using namespace ParamArgs;

extern "C"
{
    TextHandle *text_create(const char *label, const char* f_family, double f_size, cairo_font_slant_t f_slant, cairo_font_weight_t f_weight, double w, double h, double x, double y)
    {
        std::string label_safe = label ? label : "";
        std::string f_family_safe = f_family ? f_family : "";

        Text *text = new Text(label_safe, f_family_safe, f_size, f_slant, f_weight, w, h, x, y);
        return reinterpret_cast<TextHandle *>(text);
    }

    const char *text_get_label(TextHandle *ptr)
    {
        if (ptr == nullptr)
            return nullptr; // null

        Text *text = reinterpret_cast<Text *>(ptr);
        return text->get_label().c_str();
    }

    BaseHandle *text_get_base(TextHandle *ptr)
    {
        if (ptr == nullptr)
            return nullptr; // null

        BaseCT *pt = reinterpret_cast<Text *>(ptr);
        return reinterpret_cast<BaseHandle *>(pt);
    }

    void text_draw(TextHandle *ptr, cairo_t *ctx)
    {
        if (ptr == nullptr)
            return; // null

        Text *text = reinterpret_cast<Text *>(ptr);
        text->draw(ctx);
    }

    void text_free(TextHandle *ptr)
    {
        if (ptr == nullptr)
            return; // null

        Text *text = reinterpret_cast<Text *>(ptr);
        delete text;
    }
}
