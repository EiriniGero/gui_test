#include "wx/wx.h"


class toDO:public wxFrame{
    public:
        toDO();

    enum{
        ID_smth=1
    };
    private:
        void Add(wxCommandEvent& event);
        void Exit(wxCommandEvent& event);
        void Smth(wxCommandEvent& event);
        

};
