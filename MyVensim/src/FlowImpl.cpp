#include "FlowImpl.hpp"

FlowImpl :: FlowImpl(){
    begin = nullptr;
    end = nullptr;
}

FlowImpl :: FlowImpl(System *begin, System *end){
    this->begin = begin;
    this->end = end;
}

FlowImpl :: ~FlowImpl(){}

FlowImpl :: FlowImpl(Flow &flow){
    begin = flow.getBegin();
    end = flow.getEnd();
}

FlowImpl& FlowImpl :: operator=(const Flow &flow){
    if(this == &flow)
        return *this;

    begin = flow.getBegin();
    end = flow.getEnd();

    return *this;
}

void FlowImpl :: setBegin(System *begin){
    this->begin = begin;
}

System* FlowImpl :: getBegin() const{
    return begin;
}

void FlowImpl :: setEnd(System *end){
    this->end = end;
}

System* FlowImpl :: getEnd() const{
    return end;
}

bool FlowImpl :: operator==(const Flow& flow) const{
    if(begin != flow.getBegin()) 
        return false;
    
    if(end != flow.getEnd()) 
        return false;
    
    return true;
}