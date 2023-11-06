#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>
#include "system.h"

using namespace std;

class Flow{
    System *begin, *end;
public:
    Flow(System* = nullptr, System* = nullptr);
    virtual ~Flow();
    Flow (const Flow&);
    Flow& operator=(const Flow&);

    void setBegin(System*);
    System* getBegin() const;

    void setEnd(System*);
    System* getEnd() const;

    virtual double executeFunction() = 0;
};


#endif