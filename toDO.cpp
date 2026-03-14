#include "wx/wx.h"
#include "toDO.hpp"


toDO::toDO():wxFrame(nullptr,wxID_ANY,"TO DO LIST"){
    wxMenu *menu= new wxMenu;
    menu->Append(wxID_EXIT);
    menu->AppendSeparator();
    menu->Append(ID_smth,"Somthing \tCtrl-S","That is indeed somthing");
    

    wxMenuBar *bar= new wxMenuBar;
    bar->Append(menu,"Here!");
    bar->SetBackgroundColour(wxColor(240,128,128));

    SetMenuBar(bar);

    Bind(wxEVT_MENU, &toDO::Smth, this, ID_smth);
    Bind(wxEVT_MENU, &toDO::Exit, this, wxID_EXIT);

    wxPanel *panelleft= new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300,150));
    panelleft -> SetBackgroundColour(wxColor(245,245,220));

    wxPanel *panelright= new wxPanel(this, wxID_ANY,wxDefaultPosition, wxSize(300,150));
    panelright -> SetBackgroundColour(wxColor(255,228,225));

    wxPanel *panelbot= new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(300,150));
    panelbot -> SetBackgroundColour(wxColor(255,182,193));

    wxBoxSizer *sizerH= new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizer= new wxBoxSizer(wxVERTICAL);

    sizerH-> Add(panelleft, 3, wxEXPAND);
    sizerH-> Add(panelright, 2, wxEXPAND);
    sizer-> Add(sizerH, 2, wxEXPAND);
    sizer-> Add(panelbot, 1, wxEXPAND);

    this-> SetSizerAndFit(sizer);


    wxTextCtrl *text= new wxTextCtrl(panelbot, wxID_ANY, wxEmptyString, wxPoint(10,10), wxSize(200,50));
    wxButton *button= new wxButton(panelbot, ID_Button, "ADD", wxPoint(220,10), wxSize(50,50));
    
    //wxTextEntry *textent =new wxTextEntry();
}

void toDO::Exit(wxCommandEvent& event){
    Close(true);
}

void toDO::Smth(wxCommandEvent& event){
    //wxLog
}
void toDO:: Add(wxCommandEvent& event){
    //std::cout<<
}