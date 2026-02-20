#include "wx/wx.h"
#include "toDO.hpp"


toDO::toDO():wxFrame(nullptr,wxID_ANY,"TO DO LIST"){
    wxMenu *menu= new wxMenu;
    menu->Append(wxID_EXIT);
    menu->AppendSeparator();
    menu->Append(ID_smth,"Somthing \tCtrl-S","That is indeed somthing");
    

    wxMenuBar *bar= new wxMenuBar;
    bar->Append(menu,"Here!");
    bar->SetBackgroundColour(wxColor(255,103,103));

    SetMenuBar(bar);

    Bind(wxEVT_MENU, &toDO::Smth, this, ID_smth);
    Bind(wxEVT_MENU, &toDO::Exit, this, wxID_EXIT);

    wxPanel *panelbot= new wxPanel(this,wxID_ANY);
    panelbot-> SetBackgroundColour(wxColor(250,180,180));
    wxTextCtrl *text= new wxTextCtrl(panelbot,wxID_ANY);
    //wxTextEntry *textent =new wxTextEntry();
}

void toDO::Exit(wxCommandEvent& event){
    Close(true);
}

void toDO::Smth(wxCommandEvent& event){
    //wxLog
}