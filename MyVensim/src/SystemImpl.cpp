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

SystemImpl :: SystemImpl(const SystemImpl &system){
    name = system.getName();
    value = system.getValue();
}

SystemImpl& SystemImpl :: operator=(const SystemImpl& system){
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

ostream& operator<<(ostream &out, SystemImpl &system){
    out << "Name:" << system.getName() << endl << "Value:" << system.getValue() << endl;

    return out;
}