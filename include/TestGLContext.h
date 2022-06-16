#ifndef TESTGLCONTEXT_H
#define TESTGLCONTEXT_H

#include "wx/glcanvas.h"

class TestGLContext : public wxGLContext
{
public:
    TestGLContext(wxGLCanvas *wxGLCanvas);
};

#endif