#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"

/**
 * @brief Abstract base class representing a flow in a system model.
 */
class Flow {
public:
    /**
     * @brief Virtual destructor for the Flow class.
     */
    virtual ~Flow() {};

    /**
     * @brief Pure virtual function to set the beginning system of the flow.
     * @param begin The starting system of the flow.
     */
    virtual void setBegin(System*) = 0;

    /**
     * @brief Pure virtual function to get the beginning system of the flow.
     * @return A pointer to the starting system of the flow.
     */
    virtual System* getBegin() const = 0;

    /**
     * @brief Pure virtual function to set the ending system of the flow.
     * @param end The ending system of the flow.
     */
    virtual void setEnd(System*) = 0;

    /**
     * @brief Pure virtual function to get the ending system of the flow.
     * @return A pointer to the ending system of the flow.
     */
    virtual System* getEnd() const = 0;

    /**
     * @brief Pure virtual function representing the execution of the flow.
     * @return The result of the flow's execution, of type double.
     */
    virtual double executeFunction() = 0;

    /**
     * @brief Pure virtual function representing the override of the operator "=" of flow.
     */
    virtual Flow& operator=(const Flow&) = 0;

    /**
     * @brief Pure virtual function representing the override of the operator "==" of flow.
     */
    virtual bool operator==(const Flow&) const = 0;
};

#endif