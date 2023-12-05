#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"

/**
 * @brief Concrete implementation of the Flow class.
 */
class FlowImpl : public Flow {
protected:
    System *begin, *end; ///< @brief Source and Target systems of the Flow.

public:
    /**
     * @brief Default constructor for the FlowImpl class.
     */
    FlowImpl();

    /**
     * @brief Constructor that takes two System objects as parameters.
     * @param begin The starting system of the flow.
     * @param end The ending system of the flow.
     */
    FlowImpl(System*, System*);

    /**
     * @brief Destructor for the FlowImpl class.
     */
    virtual ~FlowImpl();

    /**
     * @brief Copy constructor for the FlowImpl class.
     * @param flow The Flow object to be copied.
     */
    FlowImpl(Flow&);

    /**
     * @brief Assignment operator overload.
     * @param flow The Flow object to be assigned.
     * @return A reference to the current Flow object.
     */
    FlowImpl& operator=(const Flow&);

    /**
     * @brief Set the starting system of the flow.
     * @param begin The starting system of the flow.
     */
    void setBegin(System*);

    /**
     * @brief Get the starting system of the flow.
     * @return A pointer to the starting system of the flow.
     */
    System* getBegin() const;

    /**
     * @brief Set the ending system of the flow.
     * @param end The ending system of the flow.
     */
    void setEnd(System*);

    /**
     * @brief Get the ending system of the flow.
     * @return A pointer to the ending system of the flow.
     */
    System* getEnd() const;

    /**
     * @brief Overloaded equality operator.
     * @param flow The Flow object to compare.
     * @return True if the flows are equal, false otherwise.
     */
    bool operator==(const Flow&) const;

    /**
     * @brief Pure virtual function that must be implemented in derived classes.
     *
     * Represents the execution of the flow and returns a double value.
     *
     * @return The result of the flow's execution.
     */
    virtual double executeFunction() = 0;
};

#endif