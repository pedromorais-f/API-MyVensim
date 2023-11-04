#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

using namespace std;

class Model{
    string name;
    vector<System*> systems;
    vector<Flow*> flows;
public:
    Model();
    Model(string = "");
    Model(const Model&);
    virtual ~Model();

    typedef vector<System*> :: iterator systemsIterator;
    typedef vector<Flow*> :: iterator flowsIterator;

    systemsIterator systemsBegin();
    systemsIterator systemsEnd();

    flowsIterator flowsBegin();
    flowsIterator flowsEnd();

    void setName(string);
    string getName() const;

    bool add(System*);
    bool add(Flow*);

    bool remove(System*);
    bool remove(Flow*);

    bool run(int, int);

    void summary();
};



#endif