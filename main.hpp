#include "wx/wx.h"

class mainn: public wxApp{
    private:
        bool OnInit() override;

};
wxIMPLEMENT_APP(mainn);