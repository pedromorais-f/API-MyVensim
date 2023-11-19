#include "SystemImpl.hpp"

SystemImpl :: SystemImpl(){
    name = "";
    value = 0.0;
}

SystemImpl :: SystemImpl(string name, double value){
    this->name = name;
    this->value = value;
}

SystemImpl :: ~SystemImpl(){}

SystemImpl :: SystemImpl(System &system){
    name = system.getName();
    value = system.getValue();
}

SystemImpl& SystemImpl :: operator=(const System& system){
    if(this == &system)
        return *this;

    name = system.getName();
    value = system.getValue();

    return *this;
}

void SystemImpl :: setName(string name){
    this->name = name;
}

string SystemImpl :: getName() const{
    return name;
}

void SystemImpl :: setValue(double value){
    this->value = value;
}

double SystemImpl :: getValue() const{
    return value;
}

bool SystemImpl :: operator==(const System& system) const{
    if(name != system.getName()) 
        return false;
    
    if(value != system.getValue()) 
        return false;
    
    return true;
}

ostream& operator<<(ostream &out, SystemImpl &system){
    out << "Name:" << system.getName() << endl << "Value:" << system.getValue() << endl;

    return out;
}