#include "flow.h"

Flow :: Flow(string name, System *begin, System *end){
    this->name = name;
    this->begin = begin;
}

Flow :: ~Flow(){}

Flow :: Flow(const Flow &flow){
    name = flow.getName();
    begin = flow.getBegin();
    end = flow.getEnd();
}

Flow& Flow :: operator=(const Flow &flow){
    if(this == &flow)
        return *this;

    name = flow.getName();
    begin = flow.getBegin();
    end = flow.getEnd();

    return *this;
}

void Flow :: setName(string name){
    this->name = name;
}

string Flow :: getName() const{
    return name;
}

void Flow :: setBegin(System *begin){
    this->begin = begin;
}

System* Flow :: getBegin() const{
    return begin;
}

void Flow :: setEnd(System *end){
    this->end = end;
}

System* Flow :: getEnd() const{
    return end;
}