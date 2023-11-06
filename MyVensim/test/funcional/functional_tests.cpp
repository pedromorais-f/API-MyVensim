#include "functional_tests.h"


class LogisticFlow : public Flow{
public:
    LogisticFlow(){}
    LogisticFlow(System *begin, System *end) : Flow(begin, end){}
    LogisticFlow(const LogisticFlow& lf) : Flow(lf){}
    virtual ~LogisticFlow(){}

    double executeFunction(){
        double value = getEnd()->getValue();

        return 0.01 * value * (1 - value / 70.0);
    }
};

class ExponentialFlow : public Flow{
public:
    ExponentialFlow(){}
    ExponentialFlow(System *begin, System *end) : Flow(begin, end){}
    ExponentialFlow(const ExponentialFlow& ef) : Flow(ef){}
    virtual ~ExponentialFlow(){}

    double executeFunction(){
        double value = getBegin()->getValue();
        
        return 0.01 * value;
    }
};

class ComplexFlow : public Flow{
public:
    ComplexFlow(){}
    ComplexFlow(System *begin, System *end) : Flow(begin, end){}
    ComplexFlow(const ComplexFlow& cf) : Flow(cf){}
    virtual ~ComplexFlow(){}

    double executeFunction(){
        double value = getBegin()->getValue();

        return 0.01 * value;
    }
};


void logisticTest(){
    
    cout << "\nStarting Logistic Test\n" << endl;
    
    Model model;
    System p1("P1", 100.0), p2("P2", 10.0);
    LogisticFlow logistica(&p1, &p2);

    model.add(&p1);
    model.add(&p2);
    model.add(&logistica);

    model.run(1, 100);

    model.summary();

    assert(fabs((p1.getValue()) - 88.2167) < 0.0001);
    assert(fabs((p2.getValue()) - 21.7833) < 0.0001);

    
    cout << "Logistic Test Passed\n" << endl;
}

void exponentialTest(){
    
    cout << "\nStarting Exponential Test\n" << endl;
    
    Model model;
    System pop1("POP1", 100.0), pop2("POP2", 0.0);
    ExponentialFlow exponencial(&pop1, &pop2);

    model.add(&pop1);
    model.add(&pop2);
    model.add(&exponencial);

    model.run(1, 100);

    model.summary();

    assert(fabs((pop1.getValue()) - 36.6032) < 0.0001);
    assert(fabs((pop2.getValue()) - 63.3968) < 0.0001);

    cout << "Exponential Test Passed\n" << endl;
}

void complexTest(){
    cout << "\nStarting Complex Test\n" << endl;
    
    Model model;
    System Q1("Q1", 100.0), Q2("Q2", 0.0), Q3("Q3", 100.0), Q4("Q4", 0.0), Q5("Q5", 0.0);
    ComplexFlow f(&Q1, &Q2), g(&Q1, &Q3), r(&Q2, &Q5), t(&Q2, &Q3), u(&Q3, &Q4), v(&Q4, &Q1);

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

    model.run(1, 100);

    model.summary();

    assert(fabs((Q1.getValue()) - 31.8513) < 0.0001);
    assert(fabs((Q2.getValue()) - 18.4003) < 0.0001);
    assert(fabs((Q3.getValue()) - 77.1143) < 0.0001);
    assert(fabs((Q4.getValue()) - 56.1728) < 0.0001);
    assert(fabs((Q5.getValue()) - 16.4612) < 0.0001);

    cout << "Complex Test Passed" << endl;
}