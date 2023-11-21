#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Abstract base class representing a system in a model.
 */
class System {
public:
    /**
     * @brief Virtual destructor for the System class.
     */
    virtual ~System() {};

    /**
     * @brief Pure virtual function to set the name of the system.
     * @param name The name to set for the system.
     */
    virtual void setName(string) = 0;

    /**
     * @brief Pure virtual function to get the name of the system.
     * @return The name of the system.
     */
    virtual string getName() const = 0;

    /**
     * @brief Pure virtual function to set the value of the system.
     * @param value The value to set for the system.
     */
    virtual void setValue(double) = 0;

    /**
     * @brief Pure virtual function to get the value of the system.
     * @return The value of the system.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Pure virtual function representing the override of the operator "=" of system.
     */
    virtual System& operator=(const System&) = 0;

    /**
     * @brief Pure virtual function representing the override of the operator "==" of system.
     */
    virtual bool operator==(const System&) const = 0;
};

#endif