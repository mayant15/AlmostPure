#include "Dolphin.h"

Dolphin::Dolphin() {
    love = 0;
}

Dolphin::Dolphin(string n, bool female){
    love = 0;
    name = n;
    isFemale = female;
}

// Get lots of love from the Dolphin~
int Dolphin::getLove(){
    return love;
}

