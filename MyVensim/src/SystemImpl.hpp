#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <iostream>
#include <string>
#include "System.hpp"

using namespace std;

/**
 * @brief Concrete implementation of the System class.
 */
class SystemImpl : public System {
protected:
    string name;  ///< @brief Name of the system.
    double value; ///< @brief Value associated with the system.

public:
    /**
     * @brief Default constructor for the SystemImpl class.
     */
    SystemImpl();

    /**
     * @brief Constructor that initializes a System with a name and value.
     * @param name The name of the system.
     * @param value The value associated with the system.
     */
    SystemImpl(string, double);

    /**
     * @brief Destructor for the SystemImpl class.
     */
    virtual ~SystemImpl();

    /**
     * @brief Copy constructor for the SystemImpl class.
     * @param system The System object to be copied.
     */
    SystemImpl(System&);

    /**
     * @brief Assignment operator overload.
     * @param system The System object to be assigned.
     * @return A reference to the current System object.
     */
    SystemImpl& operator=(const System&);

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

    /**
     * @brief Overloaded << operator to allow for a System object to be printed to the ostream.
     * @param out The output stream.
     * @param system The System object to be printed.
     * @return A reference to the output stream.
     */
    friend ostream& operator<<(ostream&, SystemImpl&);
};

#endif