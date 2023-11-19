#include "unit_model.hpp"

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

void unit_Model_Constructor_Default(){
    Model& model = *new ModelImpl();

    assert(model.getName() == "");

    delete &model;
}

void unit_Model_Constructor(){
    Model& model = *new ModelImpl("Model1");

    assert(model.getName() == "Model1");

    delete &model;
}

void unit_Model_Destrutor(){}

void unit_Model_setName(){
    Model& model = *new ModelImpl();
    model.setName("Model1");

    assert(model.getName() == "Model1");

    delete &model;
}

void unit_Model_getName(){
    Model& model = *new ModelImpl("Model1");

    assert(model.getName() == "Model1");

    delete &model;
}

void unit_Model_addSystem(){
    Model& model = *new ModelImpl("Model1");

    System& system1 = *new SystemImpl();

    assert(model.add(&system1));

    delete &model;
    delete &system1;
}

void unit_Model_addFlow(){
    Model& model = *new ModelImpl("Model1");

    Flow& logisticFlow = *new LogisticFlow();

    assert(model.add(&logisticFlow));

    delete &model;
    delete &logisticFlow;
}

void unit_Model_removeSystem(){
    Model& model = *new ModelImpl("Model1");

    System& system1 = *new SystemImpl();
    model.add(&system1);

    assert(model.remove(&system1));

    delete &model;
    delete &system1;
}

void unit_Model_removeFlow(){
    Model& model = *new ModelImpl("Model1");

    Flow& logisticFlow = *new LogisticFlow();
    model.add(&logisticFlow);

    assert(model.remove(&logisticFlow));

    delete &model;
    delete &logisticFlow;
}

void unit_Model_SystemBeginEnd(){
    Model& model = *new ModelImpl("Model1");

    System& system1 = *new SystemImpl();
    System& system2 = *new SystemImpl();
    model.add(&system1);
    model.add(&system2);

    assert(*model.systemsBegin() == &system1);

    int counter = 0;

    Model ::systemsIterator it = model.systemsBegin();

    while(it != model.systemsEnd()){
        counter++;
        it++;
    }

    assert(counter == model.systemsSize());
    

    delete &model;
    delete &system1;
    delete &system2;
}

void unit_Model_FlowBeginEnd(){
    Model& model = *new ModelImpl("Model1");

    Flow& logisticFlow1 = *new LogisticFlow();
    Flow& logisticFlow2 = *new LogisticFlow();
    model.add(&logisticFlow1);
    model.add(&logisticFlow2);

    assert(*model.flowsBegin() == &logisticFlow1);

    int counter = 0;

    Model :: flowsIterator it = model.flowsBegin();

    while(it != model.flowsEnd()){
        counter++;
        it++;
    }

    assert(counter == model.flowsSize());
    

    delete &model;
    delete &logisticFlow1;
    delete &logisticFlow2;
}

void unit_Model_run(){
    Model& model = *new ModelImpl("Model1");

    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 10);

    Flow& logisticFlow1 = *new LogisticFlow(&system1, &system2);

    model.add(&system1);
    model.add(&system2);
    model.add(&logisticFlow1);

    assert(model.run(0, 100));
    assert(!model.run(110, 100));
    assert(!model.run(-30, 10));
    assert(!model.run(-25, -145));

    delete &model;
    delete &system1;
    delete &system2;
    delete &logisticFlow1;
}