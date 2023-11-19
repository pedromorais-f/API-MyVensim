#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/ModelImpl.hpp"
#include "../../src/FlowImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include <assert.h>

/**
 * @brief Unit test for the default constructor of the Model class.
 */
void unit_Model_Constructor_Default();

/**
 * @brief Unit test for the parameterized constructor of the Model class.
 */
void unit_Model_Constructor();

/**
 * @brief Unit test for the destructor of the Model class.
 */
void unit_Model_Destrutor();

/**
 * @brief Unit test for the setName method of the Model class.
 */
void unit_Model_setName();

/**
 * @brief Unit test for the getName method of the Model class.
 */
void unit_Model_getName();

/**
 * @brief Unit test for the addSystem method of the Model class.
 */
void unit_Model_addSystem();

/**
 * @brief Unit test for the addFlow method of the Model class.
 */
void unit_Model_addFlow();

/**
 * @brief Unit test for the removeSystem method of the Model class.
 */
void unit_Model_removeSystem();

/**
 * @brief Unit test for the removeFlow method of the Model class.
 */
void unit_Model_removeFlow();

/**
 * @brief Unit test for the systemsBegin and systemsEnd methods of the Model class.
 */
void unit_Model_SystemBeginEnd();

/**
 * @brief Unit test for the flowsBegin and flowsEnd methods of the Model class.
 */
void unit_Model_FlowBeginEnd();

/**
 * @brief Unit test for the run method of the Model class.
 */
void unit_Model_run();

#endif