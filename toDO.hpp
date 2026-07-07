#include "wx/wx.h"
#include <vector>


class toDO:public wxFrame{
    public:
        toDO();

    enum{
        ID_ClearAll=1,
        ID_Button=2,
        ID_BtnDone=3,
        ID_Text=4,
        ID_BtnClear=5
    };
    private:
        wxTextCtrl *text;
        wxListBox *list;
        wxListBox *done;

        int count=0;
        std::vector<wxString> lista;

        void Add(wxCommandEvent& event);
        void Exit(wxCommandEvent& event);
        void ClearAll(wxCommandEvent& event);
        void Donee(wxCommandEvent& event);
        void Clear(wxCommandEvent& event);
    
    wxDECLARE_EVENT_TABLE();

};
