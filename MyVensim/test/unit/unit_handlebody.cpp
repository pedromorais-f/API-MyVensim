#include <iostream>
#include <assert.h>

#include "unit_handlebody.hpp"
#include "../../src/Model.hpp"
#include "../../src/SystemImpl.hpp"

using namespace std;

class LogisticFlow : public FlowBody{
public:
    LogisticFlow(){}
    LogisticFlow(System *begin, System *end) : FlowBody(begin, end){}
    LogisticFlow(Flow& flow) : FlowBody(flow){}
    virtual ~LogisticFlow(){}

    double executeFunction(){
        double value = getEnd()->getValue();

        return 0.01 * value * (1 - value / 70.0);
    }
};

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif

void run_unit_test_HandleBody(){
    // Create model
    Model& m = Model::createModel("Modelo Logístico.");  
    System& s1 = m.createSystem("populacao",10.0);
    System& s2 = m.createSystem("Teste", 7.90);    
    //Flow& f1 = m.createFlow<LogisticFlow>(&s1, &s2);
    m.createFlow<LogisticFlow>(&s1, &s2);    

    // USANDO REFERENCIAS PARA INTERFACE (CLASSE ABSTRATA)
    cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;
    s1 = s2;
    cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;     
    
    
    // Fa�a o teste COM e SEM as chaves abaixo
    {
        // USANDO OBJETOS HANDLES (DELEGA��O)
        SystemHandle s3("tiago", 7), s4("antonio", 8);
        cout << "s3: " << s3.getName() << ", s2: " <<  s4.getName() << endl;
        s3 = s4;  // comente esta linha e veja que o resultado muda
        cout << "s3: " << s4.getName() << ", s2: " <<  s4.getName() << endl;        
        s3 = s3;
        cout << "s3: " << s4.getName() << ", s2: " <<  s4.getName() << endl;        
    }

    assert(numHandleCreated == 6);
    assert(numBodyCreated == 6);
    
    // executa o modelo
    m.run(0,30);
    cout << s1.getValue() << endl;

    delete &m;

    assert(numHandleDeleted == 6);
    assert(numBodyDeleted == 6);

    // imprime relatorio
    cout << "Created handles: "  << numHandleCreated << endl;
    cout << "Deleted handles: "  << numHandleDeleted << endl;    
    cout << "Created bodies: "  << numBodyCreated << endl;
    cout << "Deleted bodies: "  << numBodyDeleted << endl;
}