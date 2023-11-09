#include "flow.h"

Flow :: Flow(){
    begin = nullptr;
    end = nullptr;
}

Flow :: Flow(System *begin, System *end){
    this->begin = begin;
    this->end = end;
}

Flow :: ~Flow(){}

Flow :: Flow(const Flow &flow){
    begin = flow.getBegin();
    end = flow.getEnd();
}

Flow& Flow :: operator=(const Flow &flow){
    if(this == &flow)
        return *this;

    begin = flow.getBegin();
    end = flow.getEnd();

    return *this;
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