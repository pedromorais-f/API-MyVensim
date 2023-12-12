#include "SystemImpl.hpp"

SystemBody :: SystemBody(){
    name = "";
    value = 0.0;
}

SystemBody :: SystemBody(string name, double value){
    this->name = name;
    this->value = value;
}

SystemBody :: ~SystemBody(){}


void SystemBody :: setName(string name){
    this->name = name;
}

string SystemBody :: getName() const{
    return name;
}

void SystemBody :: setValue(double value){
    this->value = value;
}

double SystemBody :: getValue() const{
    return value;
}