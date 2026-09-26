#include "../../include/crpdfcpp/line.h"
#include "../model/controls/line.hpp"

using namespace Controls;
using namespace ParamArgs;

extern "C"{

    LineHandle *line_create(double _stickless, Axis _orientation, double w, double h, double x, double y)
    {

        Line *line = new Line(_stickless, _orientation, w, h, x, y);
        return reinterpret_cast<LineHandle *>(line);
    }

     BaseHandle *line_get_base(LineHandle *ptr)
    {
        if (ptr == nullptr)
            return nullptr; // null

        BaseCT *pt = reinterpret_cast<Line *>(ptr);
        return reinterpret_cast<BaseHandle *>(pt);
    }

    void line_draw(LineHandle *ptr, cairo_t *ctx)
    {
        if (ptr == nullptr)
            return; // null

        Line *line = reinterpret_cast<Line *>(ptr);
        line->draw(ctx);
    }

    void line_free(LineHandle *ptr)
    {
        if (ptr == nullptr)
            return; // null

        Line *line = reinterpret_cast<Line *>(ptr);
        delete line;
    }
}
