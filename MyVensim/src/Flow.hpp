#ifndef FLOW_HPP
#define FLOW_HPP

#include <iostream>
#include <string>
#include "System.hpp"

using namespace std;


class Flow {
public:
    virtual ~Flow() {};

    virtual void setBegin(System*) = 0;
    virtual System* getBegin() const = 0;

    virtual void setEnd(System*) = 0;
    virtual System* getEnd() const = 0;

    virtual double executeFunction() = 0;
};

#endif