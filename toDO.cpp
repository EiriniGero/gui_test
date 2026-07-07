#include "wx/wx.h"
#include "toDO.hpp"
#include <string>
#include <vector>

wxBEGIN_EVENT_TABLE(toDO, wxFrame)
    EVT_BUTTON(ID_Button, toDO::Add)
    EVT_TEXT_ENTER(ID_Text, toDO::Add)
    EVT_BUTTON(ID_BtnDone, toDO::Donee)
    EVT_BUTTON(ID_BtnClear, toDO::Clear)
wxEND_EVENT_TABLE()

toDO::toDO():wxFrame(nullptr,wxID_ANY,"TO DO LIST"){
    //fonts
    wxFont myFont=wxFontInfo(12).Bold();
    wxFont myFontt=wxFontInfo(9).Bold();
    
    wxMenu *menu= new wxMenu;
    menu->Append(wxID_EXIT);
    menu->AppendSeparator();
    menu->Append(ID_ClearAll,"Clear All \tCtrl-D","Clear Everything");
    

    wxMenuBar *bar= new wxMenuBar;
    bar->Append(menu,"More!");
    bar->SetBackgroundColour(wxColor(240,128,128));
    bar->SetForegroundColour(wxColor(250,250,250));
    bar-> SetFont(myFontt);

    SetMenuBar(bar);

    Bind(wxEVT_MENU, &toDO::ClearAll, this, ID_ClearAll);
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



    //pano aristera lista
    wxStaticText *leftext= new wxStaticText(panelleft,wxID_ANY,"TO DO",wxPoint(155,10),wxSize(350,30));
    leftext->SetForegroundColour(wxColor(240,128,128));
    leftext->SetFont(myFont);

    list= new wxListBox(panelleft,wxID_ANY,wxPoint(10,40), wxSize(350,250),0,NULL);
    list-> SetBackgroundColour(wxColor(245,245,220));
    list-> SetForegroundColour(wxColor(61, 61, 61));
    list->SetFont(myFontt);

    wxButton *btnDone= new wxButton(panelleft,ID_BtnDone, "DONE",wxPoint(370,40),wxSize(60,50));
    btnDone-> SetForegroundColour(wxColor(250,250,250));
    btnDone-> SetBackgroundColour(wxColor(240,128,128));
    btnDone->SetFont(myFontt);

    //dejia done
    wxStaticText *rightext= new wxStaticText(panelright,wxID_ANY,"Already Done!",wxPoint(80,10),wxSize(200,30));
    rightext->SetForegroundColour(wxColor(240,128,128));
    rightext->SetFont(myFont);

    done= new wxListBox(panelright,wxID_ANY,wxPoint(35,40),wxSize(200,200));
    done-> SetBackgroundColour(wxColor(255,228,225));
    done-> SetForegroundColour(wxColor(61, 61, 61));
    done->SetFont(myFontt);

    wxButton *btnClear=new wxButton(panelright, ID_BtnClear,"CLEAR",wxPoint(35,230),wxSize(200,50));
    btnClear->SetForegroundColour(wxColor(250,250,250));
    btnClear->SetBackgroundColour(wxColor(240,128,128));
    btnClear->SetFont(myFontt);

    //kato plesio
    wxStaticText *botext= new wxStaticText(panelbot,wxID_ANY,"Do you want to add somthing?",wxPoint(10,10),wxSize(500,30));
    botext->SetForegroundColour(wxColor(47, 47, 47));
    botext->SetFont(myFontt);

    text= new wxTextCtrl(panelbot, ID_Text, wxEmptyString, wxPoint(10,35), wxSize(500,50),wxTE_PROCESS_ENTER);
    text-> SetBackgroundColour(wxColor(255,182,193));
    text-> SetForegroundColour(wxColor(47, 47, 47));
    text->SetFont(myFontt);

    wxButton *button= new wxButton(panelbot, ID_Button, "ADD", wxPoint(500,35), wxSize(60,50));
    button-> SetForegroundColour(wxColor(250,250,250));
    button-> SetBackgroundColour(wxColor(240,128,128));
    button->SetFont(myFontt);
}

void toDO::Exit(wxCommandEvent& event){
    Close(true);
}

void toDO::ClearAll(wxCommandEvent& event){
    text->Clear();
    list->Clear();
    done->Clear();
    lista.clear();
}

void toDO::Add(wxCommandEvent& event){
    wxString line = text->GetLineText(0);
    if(line!=""){
        list-> Append(line);
        text->Clear();
        lista.push_back(line);
    }
}

void toDO::Donee(wxCommandEvent& event){
    int pos= list-> GetSelection();
    if (pos!= wxNOT_FOUND){
        list-> Delete(pos);
        done->Append(lista[pos]);
        lista.erase(lista.begin()+ pos);
    }
}

void toDO::Clear(wxCommandEvent& event){
    done->Clear();
}