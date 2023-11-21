#include "unit_flow.hpp"

class LogisticFlow : public FlowImpl{
public:
    LogisticFlow(){}
    LogisticFlow(System *begin, System *end) : FlowImpl(begin, end){}
    LogisticFlow(Flow& flow) : FlowImpl(flow){}
    virtual ~LogisticFlow(){}

    double executeFunction(){
        double value = getEnd()->getValue();

        return 0.01 * value * (1 - value / 70.0);
    }
};


void unit_Flow_Constructor_Default(){
    Flow& logisticflow = *new LogisticFlow();
    
    assert(logisticflow.getBegin() == nullptr);
    assert(logisticflow.getEnd() == nullptr);
    
    delete &logisticflow;
}

void unit_Flow_Constructor(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 10);
    
    Flow& logisticflow = *new LogisticFlow(&system1, &system2);

    assert(logisticflow.getBegin() == &system1);
    assert(logisticflow.getEnd() == &system2);

    delete &logisticflow;
    delete &system1;
    delete &system2;
}

void unit_Flow_Destrutor(){}

void unit_Flow_Construtor_Copy(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 10);

    Flow& logisticflow1 = *new LogisticFlow(&system1, &system2);
    Flow& logisticflow2 = *new LogisticFlow(logisticflow1);

    assert(logisticflow1 == logisticflow2);

    delete &logisticflow1;
    delete &logisticflow2;
    delete &system1;
    delete &system2;
}

void unit_Flow_Equals(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 10);

    Flow& logisticflow1 = *new LogisticFlow(&system1, &system2);
    Flow& logisticflow2 = logisticflow1;

    assert(logisticflow1 == logisticflow2);

    delete &logisticflow1;
}

void unit_Flow_setBegin(){
    System& system1 = *new SystemImpl("System1", 100);

    Flow& logisticflow1 = *new LogisticFlow();
    logisticflow1.setBegin(&system1);

    assert(logisticflow1.getBegin() == &system1);

    delete &system1;
    delete &logisticflow1;
}

void unit_Flow_getBegin(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 10);

    Flow& logisticflow1 = *new LogisticFlow(&system1, &system2);
    assert(logisticflow1.getBegin() == &system1);

    delete &system1;
    delete &system2;
    delete &logisticflow1;
}

void unit_Flow_setEnd(){
    System& system1 = *new SystemImpl("System1", 100);

    Flow& logisticflow1 = *new LogisticFlow();
    logisticflow1.setEnd(&system1);

    assert(logisticflow1.getEnd() == &system1);

    delete &system1;
    delete &logisticflow1;
}

void unit_Flow_getEnd(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 10);

    Flow& logisticflow1 = *new LogisticFlow(&system1, &system2);
    assert(logisticflow1.getEnd() == &system2);

    delete &system1;
    delete &system2;
    delete &logisticflow1;
}



