#include "unit_test.hpp"

void run_test_System(){
    unit_System_constructor_default();

    unit_System_construtor();

    unit_System_destrutor();

    unit_System_construtor_copy();

    unit_System_operator_equals();

    unit_System_setName();

    unit_System_getName();

    unit_System_setValue();

    unit_System_getValue();

    unit_System_operator_comparison();
}