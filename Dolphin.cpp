#include "Dolphin.h"

Dolphin::Dolphin() {
    love = 0;
}

Dolphin::Dolphin(string n, bool female){
    love = 0;
    name = n;
    isFemale = female;
}

int Dolphin::getLove(){
    return love;
}

