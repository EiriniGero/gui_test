#include "wx/wx.h"
#include <vector>


class toDO:public wxFrame{
    public:
        toDO();

    enum{
        ID_smth=1,
        ID_Button=2,
        ID_BtnDone=3,
        ID_Text=4
    };
    private:
        wxTextCtrl *text;
        wxListBox *list;
        wxListBox *done;

        int count=0;
        std::vector<wxString> lista;

        void Add(wxCommandEvent& event);
        void Exit(wxCommandEvent& event);
        void Smth(wxCommandEvent& event);
        void Donee(wxCommandEvent& event);
    
    wxDECLARE_EVENT_TABLE();

};
