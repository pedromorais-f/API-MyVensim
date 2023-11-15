#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

class System{
public:
    virtual ~System() {};

    virtual void setName(string) = 0;
    virtual string getName() const = 0;

    virtual void setValue(double) = 0;
    virtual double getValue() const = 0;
};

#endif