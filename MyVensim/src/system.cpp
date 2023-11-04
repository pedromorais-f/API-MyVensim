#include "system.h"


System :: System(string name, double value){
    this->name = name;
    this->value = value;
}

System :: ~System(){}

System :: System(const System &system){
    name = system.getName();
    value = system.getValue();
}

System& System :: operator=(const System& system){
    if(this == &system)
        return *this;

    name = system.getName();
    value = system.getValue();

    return *this;
}

void System :: setName(string name){
    this->name = name;
}

string System :: getName() const{
    return name;
}

void System :: setValue(double value){
    this->value = value;
}

double System :: getValue() const{
    return value;
}

ostream& operator<<(ostream &out, System &system){
    out << "\nName:" << system.getName() << endl << "Value:" << system.getValue() << endl;

    return out;
}