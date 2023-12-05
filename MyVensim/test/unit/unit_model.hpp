#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/ModelImpl.hpp"
#include "../../src/FlowImpl.hpp"
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
 * @brief Unit test for the createSystem method of the Model class.
 */
void unit_Model_createSystem();

/**
 * @brief Unit test for the createFlow method of the Model class.
 */
void unit_Model_createFlow();

/**
 * @brief Unit test for the createModel method of the Model class.
 */
void unit_Model_createModel();

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
 * @brief Unit test for the modelsBegin and modelsEnd methods of the Model class.
 */
void unit_Model_ModelBeginEnd();

/**
 * @brief Unit test for the run method of the Model class.
 */
void unit_Model_run();

#endif
