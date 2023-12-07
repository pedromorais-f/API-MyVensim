#include "FlowImpl.hpp"


void FlowBody :: setBegin(System *begin){
    this->begin = begin;
}

System* FlowBody :: getBegin() const{
    return begin;
}

void FlowBody :: setEnd(System *end){
    this->end = end;
}

System* FlowBody :: getEnd() const{
    return end;
}