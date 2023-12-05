#include "functional_tests.hpp"


class LogisticFlow : public FlowImpl{
public:
    LogisticFlow(){}
    LogisticFlow(System *begin, System *end) : FlowImpl(begin, end){}
    virtual ~LogisticFlow(){}

    double executeFunction(){
        double value = getEnd()->getValue();

        return 0.01 * value * (1 - value / 70.0);
    }
};

class ExponentialFlow : public FlowImpl{
public:
    ExponentialFlow(){}
    ExponentialFlow(System *begin, System *end) : FlowImpl(begin, end){}
    virtual ~ExponentialFlow(){}

    double executeFunction(){
        double value = getBegin()->getValue();
        
        return 0.01 * value;
    }
};

class ComplexFlow : public FlowImpl{
public:
    ComplexFlow(){}
    ComplexFlow(System *begin, System *end) : FlowImpl(begin, end){}
    virtual ~ComplexFlow(){}

    double executeFunction(){
        double value = getBegin()->getValue();

        return 0.01 * value;
    }
};


void logisticTest(){
    
    cout << "\nStarting Logistic Test\n" << endl;
    
    Model& model = Model::createModel("Logistic Model");
    System& p1 = model.createSystem("P1", 100.0);
    System& p2 = model.createSystem("P2", 10.0);
    model.createFlow<LogisticFlow>(&p1, &p2);

    model.run(0, 100);

    model.summary();

    assert(fabs(round(p1.getValue() * 10000) - 88.2167 * 10000) < 1);
    assert(fabs(round(p2.getValue() * 10000) - 21.7833 * 10000) < 1);

    
    delete &model;

    cout << "Logistic Test Passed\n" << endl;

}

void exponentialTest(){
    
    cout << "\nStarting Exponential Test\n" << endl;
    
    Model& model = Model::createModel("Exponential Model");
    System& pop1 = model.createSystem("POP1", 100.0);
    System& pop2 = model.createSystem("POP2", 0.0);
    model.createFlow<ExponentialFlow>(&pop1, &pop2);

    model.run(0, 100);

    model.summary();

    assert(fabs(round(pop1.getValue() * 10000) - 36.6032 * 10000) < 1);
    assert(fabs(round(pop2.getValue() * 10000) - 63.3968 * 10000) < 1);

    delete &model;

    cout << "Exponential Test Passed\n" << endl;

}

void complexTest(){
    cout << "\nStarting Complex Test\n" << endl;
    
    Model& model = Model::createModel("Complex Model");
    System& Q1 = model.createSystem("Q1", 100.0); 
    System& Q2 = model.createSystem("Q2", 0.0);
    System& Q3 = model.createSystem("Q3", 100.0);
    System& Q4 = model.createSystem("Q4", 0.0);
    System& Q5 = model.createSystem("Q5", 0.0);
    model.createFlow<ComplexFlow>(&Q1, &Q2);
    model.createFlow<ComplexFlow>(&Q1, &Q3);
    model.createFlow<ComplexFlow>(&Q2, &Q5);
    model.createFlow<ComplexFlow>(&Q2, &Q3);
    model.createFlow<ComplexFlow>(&Q3, &Q4);
    model.createFlow<ComplexFlow>(&Q4, &Q1);

    model.run(0, 100);

    model.summary();

    assert(fabs(round(Q1.getValue() * 10000) - 31.8513 * 10000) < 1);
    assert(fabs(round(Q2.getValue() * 10000) - 18.4003 * 10000) < 1);
    assert(fabs(round(Q3.getValue() * 10000) - 77.1143 * 10000) < 1);
    assert(fabs(round(Q4.getValue() * 10000) - 56.1728 * 10000) < 1);
    assert(fabs(round(Q5.getValue() * 10000) - 16.4612 * 10000) < 1);

    delete &model;
    
    cout << "Complex Test Passed" << endl;

}