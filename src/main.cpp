#include <iostream>

#include <wx/app.h>
#include <wx/glcanvas.h>
class wxTest : public wxApp
{
    virtual bool OnInit() override
    {
        // /usr/bin/ld: obj/main.o: undefined reference to symbol '_ZN9wxAppBase12SafeYieldForEP8wxWindowl@@WXU_3.0'
        // /usr/bin/ld: /lib/x86_64-linux-gnu/libwx_gtk3u_core-3.0.so.0: error adding symbols: DSO missing from command line
        wxGLCanvas *canvas = new wxGLCanvas(nullptr, wxID_ANY, nullptr);
        canvas->Show();
        std::cout << "hello world\n";
        return true;
    }
};

wxIMPLEMENT_APP(wxTest);