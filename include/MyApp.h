#ifndef TESTAPP_H
#define TESTAPP_H

#include <wx/app.h>
#include <wx/frame.h>
#include <wx/sizer.h>

class MyApp : public wxApp
{
public:
    MyApp() { m_glContext = NULL; m_glStereoContext = NULL; }

    // Returns the shared context used by all frames and sets it as current for
    // the given canvas.
    TestGLContext& GetContext(wxGLCanvas *canvas, bool useStereo);

    // virtual wxApp methods
    virtual bool OnInit();
    virtual int OnExit();

private:
    // the GL context we use for all our mono rendering windows
    TestGLContext *m_glContext;
    // the GL context we use for all our stereo rendering windows
    TestGLContext *m_glStereoContext;
};


#endif
