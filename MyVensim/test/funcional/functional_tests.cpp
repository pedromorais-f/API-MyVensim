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
    
    Model& model = *new ModelImpl("Logistic Model");
    System& p1 = *new SystemImpl("P1", 100.0);
    System& p2 = *new SystemImpl("P2", 10.0);
    Flow& logistic = *new LogisticFlow(&p1, &p2);

    model.add(&p1);
    model.add(&p2);
    model.add(&logistic);

    model.run(0, 100);

    model.summary();

    assert(fabs(round(p1.getValue() * 10000) - 88.2167 * 10000) < 1);
    assert(fabs(round(p2.getValue() * 10000) - 21.7833 * 10000) < 1);

    
    delete &model;
    delete &p1;
    delete &p2;
    delete &logistic;
    cout << "Logistic Test Passed\n" << endl;

}

void exponentialTest(){
    
    cout << "\nStarting Exponential Test\n" << endl;
    
    Model& model = *new ModelImpl("Exponential Model");
    System& pop1 = *new SystemImpl("POP1", 100.0);
    System& pop2 = *new SystemImpl("POP2", 0.0);
    Flow& exponential = *new ExponentialFlow(&pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&exponential);

    model.run(0, 100);

    model.summary();

    assert(fabs(round(pop1.getValue() * 10000) - 36.6032 * 10000) < 1);
    assert(fabs(round(pop2.getValue() * 10000) - 63.3968 * 10000) < 1);

    delete &model;
    delete &pop1;
    delete &pop2;
    delete &exponential;
    cout << "Exponential Test Passed\n" << endl;

}

void complexTest(){
    cout << "\nStarting Complex Test\n" << endl;
    
    Model& model = *new ModelImpl("Complex Model");
    System& Q1 = *new SystemImpl("Q1", 100.0); 
    System& Q2 = *new SystemImpl("Q2", 0.0);
    System& Q3 = *new SystemImpl("Q3", 100.0);
    System& Q4 = *new SystemImpl("Q4", 0.0);
    System& Q5 = *new SystemImpl("Q5", 0.0);
    Flow& f = *new ComplexFlow(&Q1, &Q2);
    Flow& g = *new ComplexFlow(&Q1, &Q3);
    Flow& r = *new ComplexFlow(&Q2, &Q5);
    Flow& t = *new ComplexFlow(&Q2, &Q3);
    Flow& u = *new ComplexFlow(&Q3, &Q4);
    Flow& v = *new ComplexFlow(&Q4, &Q1);

    model.add(&Q1);
    model.add(&Q2);
    model.add(&Q3);
    model.add(&Q4);
    model.add(&Q5);
    model.add(&f);
    model.add(&g);
    model.add(&r);
    model.add(&t);
    model.add(&u);
    model.add(&v);

    model.run(0, 100);

    model.summary();

    assert(fabs(round(Q1.getValue() * 10000) - 31.8513 * 10000) < 1);
    assert(fabs(round(Q2.getValue() * 10000) - 18.4003 * 10000) < 1);
    assert(fabs(round(Q3.getValue() * 10000) - 77.1143 * 10000) < 1);
    assert(fabs(round(Q4.getValue() * 10000) - 56.1728 * 10000) < 1);
    assert(fabs(round(Q5.getValue() * 10000) - 16.4612 * 10000) < 1);

    delete &model;
    delete &Q1;
    delete &Q2;
    delete &Q3;
    delete &Q4;
    delete &Q5;
    delete &f;
    delete &g;
    delete &r;
    delete &t;
    delete &u;
    delete &v;
    cout << "Complex Test Passed" << endl;

}