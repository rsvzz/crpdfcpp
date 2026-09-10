#include <crpdfcpp/wrapper/text_wrapper.h>
#include <crpdfcpp/wrapper/limit_wrapper.h>
#include <crpdfcpp/wrapper/point_wrapper.h>
#include <crpdfcpp/controls/text.hpp>
#include <string>

using namespace controls;

extern "C"
{
    TextHandle *text_create(const char* label, double w, double h, double x, double y)
    {
        std::string label_safe = label ? label : "";
    
        Text *text = new Text(label_safe, w, h, x, y);
        return reinterpret_cast<TextHandle *>(text);
    }

    void text_free(TextHandle* ptr){
        if (ptr == nullptr) return; //null

        Text *text =  reinterpret_cast<Text*>(ptr);
        delete text;
    }

    const char* text_get_label(TextHandle* ptr){
        if (ptr == nullptr) return nullptr; //null

        Text *text =  reinterpret_cast<Text*>(ptr);
         return text->get_label().c_str();
    }

    PointHandle* text_get_point(TextHandle* ptr){
        if (ptr == nullptr) return nullptr; //null

        Point *pt =  reinterpret_cast<Text*>(ptr);
        return reinterpret_cast<PointHandle*>(pt);
    }

    LimitHandle* text_get_limit(TextHandle* ptr){
         if (ptr == nullptr) return nullptr; //null
        //cast main obj
        Limit *limit =  reinterpret_cast<Text*>(ptr);
        return reinterpret_cast<LimitHandle*>(limit);

    }


}
