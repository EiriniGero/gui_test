#include "wx/wx.h"


class toDO:public wxFrame{
    public:
        toDO();

    enum{
        ID_smth=1,
        ID_Button=2
    };
    private:
        void Add(wxCommandEvent& event);
        void Exit(wxCommandEvent& event);
        void Smth(wxCommandEvent& event);
    
    //wxDECLARE_EVENT_TABLE();

};
/*wxBEGIN_EVENT_TABLE(toDO, wxFrame)
EVT_BUTTON(ID_Button, toDO::Add)
wxEND_EVENT_TABLE()*/
