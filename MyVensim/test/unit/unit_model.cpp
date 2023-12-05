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
    Model& model = Model::createModel();

    assert(model.getName() == "");

    delete &model;
}

void unit_Model_Constructor(){
    Model& model = Model::createModel("Model1");

    assert(model.getName() == "Model1");

    delete &model;
}

void unit_Model_Destrutor(){}

void unit_Model_setName(){
    Model& model = Model::createModel();
    model.setName("Model1");

    assert(model.getName() == "Model1");

    delete &model;
}

void unit_Model_getName(){
    Model& model = Model::createModel("Model1");

    assert(model.getName() == "Model1");

    delete &model;
}

void unit_Model_createSystem(){
    Model& model = Model::createModel();

    model.createSystem();

    assert(model.systemsSize() == 1);

    delete &model;
}

void unit_Model_createFlow(){
    Model& model = Model::createModel();

    model.createFlow<LogisticFlow>();

    assert(model.flowsSize() == 1);

    delete &model;
}

void unit_Model_createModel(){
    Model& model1 = Model::createModel();
    Model& model2 = Model::createModel();

    assert(model2.modelsSize() == 2);

    delete &model1;
    delete &model2;
}

void unit_Model_removeSystem(){
    Model& model = Model::createModel();

    System& system1 = model.createSystem();

    assert(model.remove(&system1));

    delete &model;
}

void unit_Model_removeFlow(){
    Model& model = Model::createModel();

    Flow& logisticFlow = model.createFlow<LogisticFlow>();

    assert(model.remove(&logisticFlow));

    delete &model;
}

void unit_Model_SystemBeginEnd(){
    Model& model = Model::createModel();

    System& system1 = model.createSystem();
    model.createSystem();

    assert(*model.systemsBegin() == &system1);

    int counter = 0;

    Model ::systemsIterator it = model.systemsBegin();

    while(it != model.systemsEnd()){
        counter++;
        it++;
    }

    assert(counter == model.systemsSize());
    

    delete &model;
}

void unit_Model_FlowBeginEnd(){
    Model& model = Model::createModel();

    Flow& logisticFlow1 = model.createFlow<LogisticFlow>();
    model.createFlow<LogisticFlow>();

    assert(*model.flowsBegin() == &logisticFlow1);

    int counter = 0;

    Model :: flowsIterator it = model.flowsBegin();

    while(it != model.flowsEnd()){
        counter++;
        it++;
    }

    assert(counter == model.flowsSize());
    

    delete &model;
}

void unit_Model_ModelBeginEnd(){
    Model& model1 = Model::createModel();

    Model& model2 = Model::createModel();
    Model& model3 = Model::createModel();

    assert(*model3.modelsBegin() == &model1);

    int counter = 0;

    Model :: modelsIterator it = model3.modelsBegin();

    while(it != model3.modelsEnd()){
        counter++;
        it++;
    }

    assert(counter == model3.modelsSize());
    

    delete &model1;
    delete &model2;
    delete &model3;
}

void unit_Model_run(){
    Model& model = Model::createModel();


    assert(model.run(0, 100) == 100);
    assert(model.run(110, 100) == -1);
    assert(model.run(-30, 10) == -1);
    assert(model.run(-25, -145) == -1);

    delete &model;
}