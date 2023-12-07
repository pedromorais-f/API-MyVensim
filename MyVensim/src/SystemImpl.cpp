#include "SystemImpl.hpp"


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




SystemHandle :: SystemHandle(){
    pImpl_->setName("");
    pImpl_->setValue(0.0);
}

SystemHandle :: SystemHandle(string name, double value){
    pImpl_->setName(name);
    pImpl_->setValue(value);
}

SystemHandle :: ~SystemHandle(){}

SystemHandle :: SystemHandle(System &system){
    pImpl_->setName(system.getName());
    pImpl_->setValue(system.getValue());
}

SystemHandle& SystemHandle :: operator=(const System& system){
    if(this == &system)
        return *this;

    pImpl_->setName(system.getName());
    pImpl_->setValue(system.getValue());

    return *this;
}

bool SystemHandle :: operator==(const System& system) const{
    if(pImpl_->getName() != system.getName()) 
        return false;
    
    if(pImpl_->getValue() != system.getValue()) 
        return false;
    
    return true;
}