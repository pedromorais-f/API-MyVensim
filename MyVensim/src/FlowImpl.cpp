#include "FlowImpl.hpp"


FlowBody :: FlowBody(){
    begin = nullptr;
    end = nullptr;
}

FlowBody :: FlowBody(System* begin, System* end){
    this->begin = begin;
    this->end = end;
}

FlowBody :: FlowBody(const Flow& flow){
    this->begin = flow.getBegin();
    this->end = flow.getEnd();
}

FlowBody :: ~FlowBody() {}

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