#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "System.hpp"
#include "Flow.hpp"

class Model{

public:
    virtual ~Model() {};

    typedef vector<System*>::iterator systemsIterator;
    typedef vector<Flow*>::iterator flowsIterator;

    virtual systemsIterator systemsBegin() = 0;
    virtual systemsIterator systemsEnd() = 0;

    virtual flowsIterator flowsBegin() = 0;
    virtual flowsIterator flowsEnd() = 0;

    virtual void setName(string) = 0;
    virtual string getName() const = 0;

    virtual bool add(System*) = 0;
    virtual bool add(Flow*) = 0;

    virtual bool remove(System*) = 0;
    virtual bool remove(Flow*) = 0;

    virtual bool run(int, int) = 0;

    virtual void summary() = 0;
};

#endif