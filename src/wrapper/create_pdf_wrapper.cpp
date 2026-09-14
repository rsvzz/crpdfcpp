#include "../../include/crpdfcpp/create_pdf_wrapper.h"
#include "../model/controls/create_pdf.hpp"

using namespace Controls;
using namespace std;
extern "C"
{
    CrPdfHandel* crpdf_create(const char* path, double width, double height)
    {
        std::string path_safe = path ? path : "";
        CreatePDF *crpdf =  new CreatePDF(path_safe, width, height);
        return reinterpret_cast<CrPdfHandel*>(crpdf);
    }

    cairo_t* crpdf_get_context(CrPdfHandel *ptr){
           if (ptr == nullptr) return nullptr; // null

        CreatePDF *crpdf = reinterpret_cast<CreatePDF *>(ptr);
        return crpdf->get_context();
    }   

    void crpdf_free(CrPdfHandel *ptr){
        if (ptr == nullptr) return; // null

        CreatePDF *crpdf = reinterpret_cast<CreatePDF *>(ptr);
        delete crpdf;
    }
}