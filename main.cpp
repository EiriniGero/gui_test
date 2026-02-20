#include "wx/wx.h"
#include "main.hpp"
#include "toDO.hpp"


bool mainn::OnInit(){
    toDO *frame= new toDO();
    frame->Show(true);
    return true;
}