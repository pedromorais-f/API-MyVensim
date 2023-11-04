#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;



class System{
    string name;
    double value;
public:
    System(string = "", double = 0.0);
    virtual ~System();
    System(const System&);
    System& operator=(const System&);
    

    void setName(string);
    string getName() const;

    void setValue(double);
    double getValue() const;

    friend ostream& operator<<(ostream&, System&);
};

#endif