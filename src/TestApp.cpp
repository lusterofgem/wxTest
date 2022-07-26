#include <iostream>
#include <string>
#include <wx/gdicmn.h>
#include <wx/sizer.h>

#include "TestApp.h"

bool TestApp::OnInit()
{
    mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
    mainFrameSizer = new wxGridSizer(3, 3, wxSize());
    for(int i = 0; i < 9; ++i)
    {
        button[i] = new wxButton(mainFrame, wxID_ANY, std::string("button") + std::to_string(i));
    }

    // mainFrame
    mainFrame->SetSizer(mainFrameSizer);

    // mainFrameSizer
    for(int i = 0; i < 9; ++i)
    {
        mainFrameSizer->Add(button[i], 1, wxEXPAND);
    }

    // button
    button[0]->Bind(wxEVT_BUTTON, [](wxCommandEvent &commandEvent){
        std::cout << "button0 clicked!\n";
    });

    mainFrame->Show();
    return true;
}