#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include <vector>
#include "System.h"
#include "Flow.h"

using namespace std;

/**
 * @brief Declaration of the class Model
 * 
 */

class Model {
protected:
    string name; ///< @brief Name of the model.
    vector<System*> systems; ///< @brief Vector to store System objects.
    vector<Flow*> flows; ///< @brief Vector to store Flow objects.

private:
    /**
     * @brief Copy constructor for Model
     * @param model Model object to be copied
     */
    Model(const Model&);
    /**
     * @brief Assignment operator overload
     * @param model The Model object to be assigned
     * @return a reference of the class Model
     */
    Model& operator=(const Model&);

public:
    /**
     * @brief Default constructor for the Model class
     */
    Model();

    /**
     * @brief Constructor that initializes a Model with a name
     * @param name The name of the model
     */
    Model(string);

    /**
     * @brief Destructor for the Model class
     */
    virtual ~Model();

    typedef vector<System*>::iterator systemsIterator; ///< @brief Iterator for the systems vector.
    typedef vector<Flow*>::iterator flowsIterator; ///< @brief Iterator for the flows vector.

    /**
     * @brief Get an iterator pointing to the beginning of the systems vector
     * @return An iterator to the beginning of the systems vector
     */
    systemsIterator systemsBegin();

    /**
     * @brief Get an iterator pointing to the end of the systems vector
     * @return An iterator to the end of the systems vector
     */
    systemsIterator systemsEnd();

    /**
     * @brief Get an iterator pointing to the beginning of the flows vector
     * @return An iterator to the beginning of the flows vector
     */
    flowsIterator flowsBegin();

    /**
     * @brief Get an iterator pointing to the end of the flows vector
     * @return An iterator to the end of the flows vector
     */
    flowsIterator flowsEnd();

    /**
     * @brief Set the name of the model
     * @param name The name of the model
     */
    void setName(string);

    /**
     * @brief Get the name of the model
     * @return The name of the model
     */
    string getName() const;

    /**
     * @brief Add a System object to the model
     * @param system The System object to be added
     * @return True if the addition was successful, false otherwise
     */
    bool add(System*);

    /**
     * @brief Add a Flow object to the model
     * @param flow The Flow object to be added
     * @return True if the addition was successful, false otherwise
     */
    bool add(Flow*);

    /**
     * @brief Remove a System object from the model
     * @param system The System object to be removed
     * @return True if the removal was successful, false otherwise
     */
    bool remove(System*);

    /**
     * @brief Remove a Flow object from the model
     * @param flow The Flow object to be removed
     * @return True if the removal was successful, false otherwise
     */
    bool remove(Flow*);

    /**
     * @brief Run the model for a specified number of iterations
     * @param t_begin The number of iterations to run
     * @param t_end The time step for each iteration
     * @return True if the model ran successfully, false otherwise
     */
    bool run(int, int);

    /**
     * @brief Print a summary of the model's systems and flows
     */
    void summary();
};

#endif