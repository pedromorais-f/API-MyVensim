#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"
#include <assert.h>

/**
 * @brief Unit test for the default constructor of the Flow class.
 */
void unit_Flow_Constructor_Default();

/**
 * @brief Unit test for the parameterized constructor of the Flow class.
 */
void unit_Flow_Constructor();

/**
 * @brief Unit test for the destructor of the Flow class.
 */
void unit_Flow_Destrutor();

/**
 * @brief Unit test for the copy constructor of the Flow class.
 */
void unit_Flow_Construtor_Copy();

/**
 * @brief Unit test for the equality comparison of the Flow class.
 */
void unit_Flow_Equals();

/**
 * @brief Unit test for the setBegin method of the Flow class.
 */
void unit_Flow_setBegin();

/**
 * @brief Unit test for the getBegin method of the Flow class.
 */
void unit_Flow_getBegin();

/**
 * @brief Unit test for the setEnd method of the Flow class.
 */
void unit_Flow_setEnd();

/**
 * @brief Unit test for the getEnd method of the Flow class.
 */
void unit_Flow_getEnd();

#endif