#ifndef TESTAPP_H
#define TESTAPP_H

#include <wx/wx.h>

class TestApp : public wxApp
{
    wxFrame mainFrame;
    wxBoxSizer mainFrameSizer;

public:
    virtual bool OnInit();
};


#endif
