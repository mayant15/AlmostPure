#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Event.h"
#include "Dolphin.h"

using namespace std;

string readLine(ifstream& in){
    string ss = "";
    string line;
    
    getline(in, line);
    
    while(line != "----"){
        ss += line + '\n';
        getline(in, line);
    }
    
    return ss;
}


int main(void) {
    
    Dolphin meriel("Meriel", true);
    Dolphin lePoo("Le Poo", false);
    
    int resp;
    string m;
    vector<string> op;
    
    Event* e;
    Event* e1;
    Event* currentEvent;
    
    ifstream infile;
    infile.open("script.txt");
    
    
   /*Setup the Tree here*/
    
    m = readLine(infile);
    Event instructions(m, 0, 0);
    
    m = readLine(infile);
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    Event start(m, op, 0, 0);
    op.clear();
    
    instructions.setNext(&start);
    
    //if punched
    m = readLine(infile);
    e = new Event(m , 0, 0);
    start.setNext(e);
    
    //if not punched
    m = readLine(infile);
    e = new Event(m , 0, 0);
    start.setNext(e);
    
    
    //Random monologue
    m = readLine(infile);
    e = new Event(m, 0, 0);
    start.getNext(1)->setNext(e);
    start.getNext(2)->setNext(e);
    
    //Talk with king
    m = readLine(infile);
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    e1 = new Event(m, op, 0, 0);
    e->setNext(e1);
    op.clear();
    
    //if joke getting old
    m = readLine(infile);
    e = new Event(m, 0, 0);
    e1->setNext(e);
    
    //if joined
    m = readLine(infile);
    e = new Event(m, 0, 0);
    e1->setNext(e);
    
    //Merial question
    m = readLine(infile);
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    e = new Event(m, op, 0, 0);
    e1->getNext(1)->setNext(e);
    e1->getNext(2)->setNext(e);
    op.clear();
    
    //grill or fry?
    m = readLine(infile);
    e1 = new Event(m, -2, 0);
    e->setNext(e1);
    
    //work?
    m = readLine(infile);
    e1 = new Event(m, 2, 0);
    e->setNext(e1);
    
    //going to the room and meeting Mario
    m = readLine(infile);
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    e1 = new Event(m, op, 0, 0);
    e->getNext(1)->setNext(e1);
    e->getNext(2)->setNext(e1);
    op.clear();
    
    //start conversation
    m = readLine(infile);
    e = new Event(m, 0, 0);
    e1->setNext(e);
    
    //reached room
    m = readLine(infile);
    e = new Event(m, 0, 0);
    e1->setNext(e);
    e1->getNext(1)->setNext(e);
    
    //Inside room
    m = readLine(infile);
    e1 = new Event(m, 0, 0);
    e->setNext(e1);
    
    //Doraemon
    m = readLine(infile);
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    e = new Event(m, op, 0, 0);
    e1->setNext(e);
    op.clear();
    
    //peek
    m = readLine(infile);
    e1 = new Event(m, -2, 0);
    e->setNext(e1);
    
    //Ignore
    m = readLine(infile);
    e1 = new Event(m, 0, 0);
    e->setNext(e1);
    
    //Photo shoot morning
    m = readLine(infile);
    e1 = new Event(m, 0, 0);
    e->getNext(1)->setNext(e1);
    e->getNext(2)->setNext(e1);
    
    //Stan Lee
    m = readLine(infile);
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    op.push_back(readLine(infile));
    e = new Event(m, op, 0, 0);
    e1->setNext(e);
    
    //fit
    m = readLine(infile);
    e1 = new Event(m, 0, 0);
    e->setNext(e1);
    
    //meet meriel
    m = readLine(infile);
    Event* e2 = new Event(m, 0, 0);
    e->setNext(e2);
    e1->setNext(e2);
    
    //look around
    m = readLine(infile);
    Event* e3 = new Event(m, 0, 0);
    e->setNext(e3);
    
    //meriel late
    m = readLine(infile);
    e1 = new Event(m, 3, 0);
    e3->setNext(e1);
    
    //Le Poo Intro Deck
    m = readLine(infile);
    e = new Event(m, 0, 0);
    e1->setNext(e);
    e2->setNext(e);
    
    //end
    m = readLine(infile);
    e1 = new Event(m, 0, 0);
    e->setNext(e1);
    
    
    
    
    currentEvent = &instructions;
    infile.close();
    
    do{
        currentEvent->updateStats(meriel,lePoo);
        
        currentEvent->trigger();
        
        cin >> resp;
        
        while(resp == 0){
            cout << endl << "STATS" << endl << "Meriel: " << meriel.getLove() << " Le Poo: " << lePoo.getLove() << endl << endl;
            cin >> resp;
        }
        
        
        currentEvent = currentEvent->getNext(resp);
        
        
    } while(1);
    
    currentEvent->trigger();
    
    return 0;
}

