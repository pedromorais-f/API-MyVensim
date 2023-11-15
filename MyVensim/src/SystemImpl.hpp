#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <iostream>
#include <string>
#include "System.hpp"

using namespace std;

/**
 * @brief Declaration of the class System
 * 
 */

class SystemImpl : public System{
protected:
    string name;  ///< @brief Name of the system.
    double value; ///< @brief Value associated with the system.

public:
    /**
     * @brief Default constructor for the System class
     */
    SystemImpl();

    /**
     * @brief Constructor that initializes a System with a name and value
     * @param name The name of the system
     * @param value The value associated with the system
     */
    SystemImpl(string, double);

    /**
     * @brief Destructor for the System class
     */
    virtual ~SystemImpl();

    /**
     * @brief Copy constructor for the System class
     * @param system The System object to be copied
     */
    SystemImpl(const SystemImpl&);

    /**
     * @brief Assignment operator overload
     * @param system The System object to be assigned
     * @return A reference to the current System object
     */
    SystemImpl& operator=(const SystemImpl&);

    /**
     * @brief Set the name of the system
     * @param name The name of the system
     */
    void setName(string);

    /**
     * @brief Get the name of the system
     * @return The name of the system
     */
    string getName() const;

    /**
     * @brief Set the value associated with the system
     * @param value The value associated with the system
     */
    void setValue(double);

    /**
     * @brief Get the value associated with the system
     * @return The value associated with the system
     */
    double getValue() const;

    /**
     * @brief Overloaded << operator to allow for system object to be printed to the ostream
     * @param out The output stream
     * @param system The System object to be printed
     * @return A reference to the output stream
     */
    friend ostream& operator<<(ostream&, SystemImpl&);
};

#endif