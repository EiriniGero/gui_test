#include "wx/wx.h"


class toDO:public wxFrame{
    public:
        toDO();

    enum{
        ID_smth=1,
        ID_Button=2,
        ID_Text=3
    };
    private:
        wxTextCtrl *text;

        void Add(wxCommandEvent& event);
        void Exit(wxCommandEvent& event);
        void Smth(wxCommandEvent& event);
    
    wxDECLARE_EVENT_TABLE();

};
