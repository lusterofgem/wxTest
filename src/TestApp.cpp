#include <wx/frame.h>

#include "TestApp.h"

bool TestApp::OnInit()
{
    wxFrame *mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
    
    mainFrame->Show();

    return true;
}