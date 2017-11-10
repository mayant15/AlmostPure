#include "Event.h"

using namespace std;


Event::Event() {
    fStats = 0;
    mStats = 0;
}

Event::Event(string s, vector<string> op, int f, int m){
    message = s;
    fStats = f;
    mStats = m;
    options = op;
}

Event::Event(string s, int f, int m){
    message = s;
    fStats = f;
    mStats = m;
}

void Event::trigger(){
    
    cout << endl << message << endl;
    
    if(nextEvent.empty()){
        exit(0);
    }
    
    if(!options.empty()){
        for(int i = 1; i <= options.size(); i++){
            cout << i << ". " << options.at(i-1) << endl;
        }
    }
}

Event* Event::getNext(int n){
    return nextEvent.at(n-1);
}

void Event::setNext(Event* e){
    nextEvent.push_back(e);
}

void Event::setOptions(vector<string> op){
    options = op;
}

void Event::setMessage(string m){
    message = m;
}

void Event::updateStats(Dolphin& f, Dolphin& m){    
    f.love = f.love + fStats;
    m.love = m.love + mStats;
}