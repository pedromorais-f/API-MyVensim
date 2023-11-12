#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "System.h"
#include "Flow.h"

using namespace std;

class Model{
protected:
    string name;
    vector<System*> systems;
    vector<Flow*> flows;
private:
    Model(const Model&);
    Model& operator=(const Model&);
public:
    Model();
    Model(string);
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