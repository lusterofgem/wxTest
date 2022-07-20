#ifndef TESTAPP_H
#define TESTAPP_H

#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/sizer.h>

class TestApp : public wxApp
{
    wxFrame *mainFrame;
    wxBoxSizer *mainFrameSizer;
    wxButton *testButton;

public:
    virtual bool OnInit();
};


#endif
