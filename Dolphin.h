#ifndef DOLPHIN_H
#define DOLPHIN_H

#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Dolphin {
public:
    int love;
    bool isFemale;
    string name;
    
    Dolphin();
    Dolphin(string n, bool female);

    int getLove();

};

#endif /* DOLPHIN_H */

