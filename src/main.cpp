#include <GL/gl.h>
#include <iostream>

#include <wx/app.h>
#include <wx/frame.h>
#include <wx/glcanvas.h>

#include "TestGLContext.h"

class wxTest : public wxApp
{
    virtual bool OnInit() override
    {
        wxFrame *mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
        // wxWidgets/src/unix/glegl.cpp(513): assert ""Assert failure"" failed in CreateSurface(): Unable to create EGL surface
        wxGLCanvas *glCanvas = new wxGLCanvas(mainFrame, wxID_ANY);
        TestGLContext *testGLContext = new TestGLContext(glCanvas);
        std::cout << std::boolalpha << testGLContext->IsOK() << "\n";
        
        // testGLContext->
        mainFrame->Show();

        return true;
    }
};

wxIMPLEMENT_APP(wxTest);
