#include "wx/wx.h"
#include "toDO.hpp"
#include <string>
#include <vector>

wxBEGIN_EVENT_TABLE(toDO, wxFrame)
    EVT_BUTTON(ID_Button, toDO::Add)
    EVT_TEXT_ENTER(ID_Text, toDO::Add)
    EVT_BUTTON(ID_BtnDone, toDO::Donee)
wxEND_EVENT_TABLE()

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


    //pano plesio lista
    list= new wxListBox(panelleft,wxID_ANY,wxPoint(10,10), wxSize(350,250),0,NULL);
    wxButton *btnDone= new wxButton(panelleft,ID_BtnDone, "Done",wxPoint(365,10),wxSize(50,50));

    //kato plesio
    text= new wxTextCtrl(panelbot, ID_Text, wxEmptyString, wxPoint(10,10), wxSize(200,50),wxTE_PROCESS_ENTER,wxDefaultValidator,"Heloo");
    wxButton *button= new wxButton(panelbot, ID_Button, "ADD", wxPoint(220,10), wxSize(50,50));

    //dejia done
    wxStaticText *m= new wxStaticText(panelright,wxID_ANY,"Already Done!");
    done= new wxListBox(panelright,wxID_ANY,wxPoint(20,30),wxSize(200,200));
}

void toDO::Exit(wxCommandEvent& event){
    Close(true);
}

void toDO::Smth(wxCommandEvent& event){
    //wxLog
}

void toDO::Add(wxCommandEvent& event){
    wxString line = text->GetLineText(0);
    list-> Append(line);
    lista.push_back(line);
    
}

void toDO::Donee(wxCommandEvent& event){
    int pos= list-> GetSelection();
    if (pos!= wxNOT_FOUND){
        list-> Delete(pos);
        done->Append(lista[pos]);
    }
}