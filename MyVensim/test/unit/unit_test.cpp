#include "unit_test.hpp"
#include "unit_system.hpp"
#include "unit_flow.hpp"
#include "unit_model.hpp"

void run_test_System(){
    unit_System_Constructor_Default();

    unit_System_Construtor();

    unit_System_Destrutor();

    unit_System_Construtor_Copy();

    unit_System_Equals();

    unit_System_setName();

    unit_System_getName();

    unit_System_setValue();

    unit_System_getValue();
}

void run_test_Flow(){
    unit_Flow_Constructor_Default();

    unit_Flow_Constructor();

    unit_Flow_Destrutor();

    unit_Flow_Construtor_Copy();

    unit_Flow_Equals();

    unit_Flow_setBegin();

    unit_Flow_getBegin();

    unit_Flow_setEnd();

    unit_Flow_getEnd();
}

void run_test_Model(){
    
    unit_Model_Constructor_Default();
    
    unit_Model_Constructor();
    
    unit_Model_Destrutor();
    
    unit_Model_setName();
    
    unit_Model_getName();
    
    unit_Model_createSystem();
    
    unit_Model_createFlow();

    unit_Model_createModel();

    unit_Model_removeSystem();

    unit_Model_removeFlow();

    unit_Model_SystemBeginEnd();

    unit_Model_FlowBeginEnd();

    unit_Model_ModelBeginEnd();

    unit_Model_run();
}