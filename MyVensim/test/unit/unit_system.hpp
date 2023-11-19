#ifndef UNIT_SYSTEM_HPP
#define UNIT_SYSTEM_HPP

#include <assert.h>
#include <cmath>
#include "../../src/SystemImpl.hpp"

/**
 * @brief Unit test for the default constructor of the System class.
 */
void unit_System_Constructor_Default();

/**
 * @brief Unit test for the parameterized constructor of the System class.
 */
void unit_System_Construtor();

/**
 * @brief Unit test for the destructor of the System class.
 */
void unit_System_Destrutor();

/**
 * @brief Unit test for the copy constructor of the System class.
 */
void unit_System_Construtor_Copy();

/**
 * @brief Unit test for the equality comparison of the System class.
 */
void unit_System_Equals();

/**
 * @brief Unit test for the setName method of the System class.
 */
void unit_System_setName();

/**
 * @brief Unit test for the getName method of the System class.
 */
void unit_System_getName();

/**
 * @brief Unit test for the setValue method of the System class.
 */
void unit_System_setValue();

/**
 * @brief Unit test for the getValue method of the System class.
 */
void unit_System_getValue();

/**
 * @brief Unit test for the comparison of two System objects.
 */
void unit_System_compare();

#endif