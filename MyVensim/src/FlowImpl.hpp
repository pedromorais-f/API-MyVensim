#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"
#include "HandleBody.hpp"

/**
 * @brief Concrete implementation of the Flow class.
 */
class FlowBody : public Body {
protected:
    System *begin, *end; ///< @brief Source and Target systems of the Flow.
public:
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
     * @brief Pure virtual function that must be implemented in derived classes.
     *
     * Represents the execution of the flow and returns a double value.
     *
     * @return The result of the flow's execution.
     */
    virtual double executeFunction() = 0;
};


template <class T>
class FlowHandle : public Flow, public Handle<T>{
public:
    /**
     * @brief Default constructor for the FlowImpl class.
     */
    FlowHandle(){
        Handle<T> :: pImpl_->setBegin(nullptr);
        Handle<T> :: pImpl_->setEnd(nullptr);
    }

    /**
     * @brief Constructor that takes two System objects as parameters.
     * @param begin The starting system of the flow.
     * @param end The ending system of the flow.
     */
    FlowHandle(System *begin, System *end){
        Handle<T> :: pImpl_->setBegin(begin);
        Handle<T> :: pImpl_->setEnd(end);
    }

    /**
     * @brief Destructor for the FlowImpl class.
     */
    virtual ~FlowHandle(){}

    /**
     * @brief Copy constructor for the FlowImpl class.
     * @param flow The Flow object to be copied.
     */
    FlowHandle(Flow& flow){
        Handle<T> :: pImpl_->setBegin(flow.getBegin());
        Handle<T> :: pImpl_->setEnd(flow.getEnd());
    }

    /**
     * @brief Assignment operator overload.
     * @param flow The Flow object to be assigned.
     * @return A reference to the current Flow object.
     */
    FlowHandle& operator=(const Flow& flow){
        if(this == &flow)
        return *this;

        Handle<T> :: pImpl_->setBegin(flow.getBegin());
        Handle<T> :: pImpl_->setEnd(flow.getEnd());

        return *this;
    }

    /**
     * @brief Set the starting system of the flow.
     * @param begin The starting system of the flow.
     */
    void setBegin(System *begin){
        Handle<T> :: pImpl_->setBegin(begin);
    }

    /**
     * @brief Get the starting system of the flow.
     * @return A pointer to the starting system of the flow.
     */
    System* getBegin() const{
        return Handle<T> :: pImpl_->getBegin();
    }

    /**
     * @brief Set the ending system of the flow.
     * @param end The ending system of the flow.
     */
    void setEnd(System *end){
        Handle<T> :: pImpl_->setEnd(end);
    }

    /**
     * @brief Get the ending system of the flow.
     * @return A pointer to the ending system of the flow.
     */
    System* getEnd() const{
        return Handle<T> :: pImpl_->getEnd();
    }

    /**
     * @brief Overloaded equality operator.
     * @param flow The Flow object to compare.
     * @return True if the flows are equal, false otherwise.
     */
    bool operator==(const Flow& flow) const{
        if(Handle<T> :: pImpl_->getBegin() != flow.getBegin()) 
            return false;
    
        if(Handle<T> :: pImpl_->getEnd() != flow.getEnd()) 
            return false;
    
        return true;
    }

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
