#include <iostream>

#include <wx/app.h>
#include <wx/glcanvas.h>

class wxTest : public wxApp
{
    virtual bool OnInit() override
    {
        wxGLCanvas *canvas = new wxGLCanvas(nullptr, wxID_ANY, nullptr);
        canvas->Show();
        std::cout << "hello world\n";
        return true;
    }
};

wxIMPLEMENT_APP(wxTest);