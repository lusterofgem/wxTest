#include "TestApp.h"

bool TestApp::OnInit()
{
    mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
    mainFrameSizer = new wxBoxSizer(wxVERTICAL);
    glCanvas = new GLCanvas(mainFrame);

    // mainFrame
    mainFrame->SetSizer(mainFrameSizer);

    // mainFrameSizer
    mainFrameSizer->Add(glCanvas);

    mainFrame->Show();

    return true;
}
