#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.hpp"
#include "HandleBody.hpp"

/**
 * @brief Concrete implementation of the System class.
 */
class SystemBody : public Body {
protected:
    string name;  ///< @brief Name of the system.
    double value; ///< @brief Value associated with the system.

public:
    /**
     * @brief Set the name of the system.
     * @param name The name of the system.
     */
    void setName(string);

    /**
     * @brief Get the name of the system.
     * @return The name of the system.
     */
    string getName() const;

    /**
     * @brief Set the value associated with the system.
     * @param value The value associated with the system.
     */
    void setValue(double);

    /**
     * @brief Get the value associated with the system.
     * @return The value associated with the system.
     */
    double getValue() const;
};


class SystemHandle : public System, public Handle<SystemBody> {
public:
    /**
     * @brief Default constructor for the SystemImpl class.
     */
    SystemHandle();

    /**
     * @brief Constructor that initializes a System with a name and value.
     * @param name The name of the system.
     * @param value The value associated with the system.
     */
    SystemHandle(string, double);

    /**
     * @brief Destructor for the SystemImpl class.
     */
    virtual ~SystemHandle();

    /**
     * @brief Copy constructor for the SystemImpl class.
     * @param system The System object to be copied.
     */
    SystemHandle(System&);

    /**
     * @brief Assignment operator overload.
     * @param system The System object to be assigned.
     * @return A reference to the current System object.
     */
    SystemHandle& operator=(const System&);

    /**
     * @brief Set the name of the system.
     * @param name The name of the system.
     */
    void setName(string);

    /**
     * @brief Get the name of the system.
     * @return The name of the system.
     */
    string getName() const;

    /**
     * @brief Set the value associated with the system.
     * @param value The value associated with the system.
     */
    void setValue(double);

    /**
     * @brief Get the value associated with the system.
     * @return The value associated with the system.
     */
    double getValue() const;

    /**
     * @brief Overloaded equality operator.
     * @param system The System object to compare.
     * @return True if the systems are equal, false otherwise.
     */
    bool operator==(const System&) const;
};

#endif