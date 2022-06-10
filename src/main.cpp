#include <iostream>

#include <wx/app.h>
#include <wx/frame.h>
#include <wx/glcanvas.h>

class wxTest : public wxApp
{
    virtual bool OnInit() override
    {
        // /usr/bin/ld: obj/main.o: undefined reference to symbol '_ZN9wxAppBase12SafeYieldForEP8wxWindowl@@WXU_3.0'
        // /usr/bin/ld: /lib/x86_64-linux-gnu/libwx_gtk3u_core-3.0.so.0: error adding symbols: DSO missing from command line
        wxFrame *mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
        wxGLCanvas *canvas = new wxGLCanvas(mainFrame, wxID_ANY, nullptr);
        
        return true;
    }
};

wxIMPLEMENT_APP(wxTest);