#include <iostream>

#include "TestApp.h"

bool TestApp::OnInit()
{
    mainFrame = new wxFrame(nullptr, wxID_ANY, "wxTest");
    mainFrameSizer = new wxBoxSizer(wxVERTICAL);
    testButton = new wxButton(mainFrame, wxID_ANY, "test button");

    // mainFrame
    mainFrame->SetSizer(mainFrameSizer);
    mainFrame->Show();

    // mainFrameSizer
    mainFrameSizer->Add(testButton);

    // testButton
    testButton->Bind(wxEVT_BUTTON, [](wxCommandEvent &commandEvent){
        std::cout << "testButton clicked!\n";
    });

    return true;
}