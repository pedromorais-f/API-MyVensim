#include "unit_system.hpp"

void unit_System_Constructor_Default(){
    System& system = *new SystemImpl();

    assert(system.getName() == "");
    assert(system.getValue() == 0.0);
    
    delete &system;
}

void unit_System_Construtor(){
    System& system = *new SystemImpl("System1", 100);

    assert(system.getName() == "System1");
    assert(fabs(round(system.getValue() * 10000) - 100 * 10000) < 1);
    
    delete &system;
}

void unit_System_Destrutor(){}

void unit_System_Construtor_Copy(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl(system1);

    assert(system1.getName() == system2.getName());
    assert(system1.getValue() == system2.getValue());

    delete &system1;
    delete &system2;
}

void unit_System_Equals(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = *new SystemImpl("System2", 100);
    System& system3 = system1;

    assert(&system1 != &system2); 
    assert(&system1 == &system3); 

    delete &system1;
    delete &system2;
}

void unit_System_setName(){
    System& system = *new SystemImpl();
    system.setName("System1");
    
    assert(system.getName() == "System1");
    
    delete &system;
}

void unit_System_getName(){
    System& system = *new SystemImpl("System1", 100);
    
    assert(system.getName() == "System1");
    
    delete &system;
}

void unit_System_setValue(){
    System& system = *new SystemImpl();
    system.setValue(100);
    
    assert(fabs(round(system.getValue() * 10000) - 100 * 10000) < 1);

    delete &system;
}

void unit_System_getValue(){
    System& system = *new SystemImpl("Sistema1", 100);

    assert(fabs(round(system.getValue() * 10000) - 100 * 10000) < 1);

    delete &system;
}

void unit_System_compare(){
    System& system1 = *new SystemImpl("System1", 100);
    System& system2 = system1;

    assert(&system1 == &system2); 

    delete &system1;
}