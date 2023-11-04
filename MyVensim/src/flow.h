#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>
#include "system.h"

using namespace std;

class Flow{
    string name;
    System *begin, *end;
public:
    Flow(string="", System* = nullptr, System* = nullptr);
    virtual ~Flow();
    Flow (const Flow&);
    Flow& operator=(const Flow&);

    void setName(string);
    string getName() const;

    void setBegin(System*);
    System* getBegin() const;

    void setEnd(System*);
    System* getEnd() const;

    virtual double setFunction() = 0;
};


#endif