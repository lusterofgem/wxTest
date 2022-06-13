#include <iostream>

#include <wx/app.h>
#include <wx/frame.h>
#include <wx/glcanvas.h>

class wxTest : public wxApp
{
    virtual bool OnInit() override
    {
        wxFrame *mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
        wxGLCanvas *canvas = new wxGLCanvas(mainFrame, wxID_ANY, nullptr);
        mainFrame->Show();
        
        return true;
    }
};

wxIMPLEMENT_APP(wxTest);
