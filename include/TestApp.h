#ifndef TESTAPP_H
#define TESTAPP_H

#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/sizer.h>

class TestApp : public wxApp
{
    wxFrame *mainFrame;
    wxGridSizer *mainFrameSizer;
    wxButton *button[9];

public:
    virtual bool OnInit();
};


#endif
