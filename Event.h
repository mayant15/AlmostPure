#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Dolphin.h"

using namespace std;

class Event {
    
private:
    
    //event details
    string message;
    vector <string> options;
    int fStats;
    int mStats;
    
    //linked events
    vector<Event*> nextEvent;
    
public:
    
    //constructors
    Event();
    Event(string s, vector<string> op, int f, int m);
    Event(string s, int f, int m);
    
    //getters
    Event* getNext(int n);
    
    //setters
    void setMessage(string m);
    void setNext(Event* e);
    void setOptions(vector<string> op);
    
    //methods
    void updateStats(Dolphin& f, Dolphin& m);
    void trigger();

    
};

#endif /* EVENT_H */

