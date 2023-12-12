#include "unit_system.hpp"
#include <assert.h>
#include <cmath>
#include "../../src/SystemImpl.hpp"

void unit_System_Constructor_Default(){
    System& system = *new SystemHandle();

    assert(system.getName() == "");
    assert(system.getValue() == 0.0);
    
    delete &system;
}

void unit_System_Construtor(){
    System& system = *new SystemHandle("System1", 100);

    assert(system.getName() == "System1");
    assert(fabs(round(system.getValue() * 10000) - 100 * 10000) < 1);
    
    delete &system;
}

void unit_System_Destrutor(){}

void unit_System_Construtor_Copy(){
    System& system1 = *new SystemHandle("System1", 100);
    System& system2 = *new SystemHandle(system1);

    assert(system1 == system2);

    delete &system1;
    delete &system2;
}

void unit_System_Equals(){
    System& system1 = *new SystemHandle("System1", 100);
    System& system2 = system1;

    assert(system1 == system2); 

    delete &system1;
}

void unit_System_setName(){
    System& system = *new SystemHandle();
    system.setName("System1");
    
    assert(system.getName() == "System1");
    
    delete &system;
}

void unit_System_getName(){
    System& system = *new SystemHandle("System1", 100);
    
    assert(system.getName() == "System1");
    
    delete &system;
}

void unit_System_setValue(){
    System& system = *new SystemHandle();
    system.setValue(100);
    
    assert(fabs(round(system.getValue() * 10000) - 100 * 10000) < 1);

    delete &system;
}

void unit_System_getValue(){
    System& system = *new SystemHandle("Sistema1", 100);

    assert(fabs(round(system.getValue() * 10000) - 100 * 10000) < 1);

    delete &system;
}