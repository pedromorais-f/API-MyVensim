#ifndef FUNCTIONAL_TESTS_HPP
#define FUNCTIONAL_TESTS_HPP

#include <iostream>
#include <assert.h>
#include <cmath>
#include "../../src/ModelImpl.hpp"
#include "../../src/FlowImpl.hpp"
#include "../../src/SystemImpl.hpp"

using namespace std;

/**
 * @brief Function to perform a logistic test.
 */
void logisticTest();

/**
 * @brief Function to perform an exponential test.
 */
void exponentialTest();

/**
 * @brief Function to perform a complex test.
 */
void complexTest();

#endif