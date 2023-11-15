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

FlowImpl :: FlowImpl(const FlowImpl &flow){
    begin = flow.getBegin();
    end = flow.getEnd();
}

FlowImpl& FlowImpl :: operator=(const FlowImpl &flow){
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