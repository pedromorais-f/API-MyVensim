#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>
#include "System.h"

using namespace std;

/**
 * @brief Declaration of the class Flow
 * 
 */

class Flow {
protected:
    System *begin, *end; ///< @brief Source and Target of the class Flow.

public:
    /**
     * @brief Default constructor for the Flow class
     */
    Flow();

    /**
     * @brief Constructor that takes two System objects as parameters
     * @param begin The starting system of the flow
     * @param end The ending system of the flow
     */
    Flow(System*, System*);

    /**
     * @brief Destructor for the Flow class
     */
    virtual ~Flow();

    /**
     * @brief Copy constructor for the Flow class
     * @param flow The Flow object to be copied
     */
    Flow(const Flow&);

    /**
     * @brief Assignment operator overload
     * @param flow The Flow object to be assigned
     * @return A reference to the current Flow object
     */
    Flow& operator=(const Flow&);

    /**
     * @brief Set the starting system of the flow
     * @param begin The starting system of the flow
     */
    void setBegin(System*);

    /**
     * @brief Get the starting system of the flow
     * @return A pointer to the starting system of the flow
     */
    System* getBegin() const;

    /**
     * @brief Set the ending system of the flow
     * @param end The ending system of the flow
     */
    void setEnd(System*);

    /**
     * @brief Get the ending system of the flow
     * @return A pointer to the ending system of the flow
     */
    System* getEnd() const;

    /**
     * @brief Pure virtual function that must be implemented in derived classes.
     *
     * Represents the execution of the flow and returns a double value.
     *
     * @return The result of the flow's execution
     */
    virtual double executeFunction() = 0;
};

#endif