#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "System.hpp"
#include "Flow.hpp"

/**
 * @brief Abstract base class representing a model with systems and flows.
 */
class Model {
public:
    /**
     * @brief Virtual destructor for the Model class.
     */
    virtual ~Model() {};

    typedef vector<System*>::iterator systemsIterator; ///< @brief Iterator for the systems vector.
    typedef vector<Flow*>::iterator flowsIterator; ///< @brief Iterator for the flows vector.

    /**
     * @brief Get an iterator pointing to the beginning of the systems vector.
     * @return An iterator to the beginning of the systems vector.
     */
    virtual systemsIterator systemsBegin() = 0;

    /**
     * @brief Get an iterator pointing to the end of the systems vector.
     * @return An iterator to the end of the systems vector.
     */
    virtual systemsIterator systemsEnd() = 0;

    /**
     * @brief Get an iterator pointing to the beginning of the flows vector.
     * @return An iterator to the beginning of the flows vector.
     */
    virtual flowsIterator flowsBegin() = 0;

    /**
     * @brief Get an iterator pointing to the end of the flows vector.
     * @return An iterator to the end of the flows vector.
     */
    virtual flowsIterator flowsEnd() = 0;

    /**
     * @brief Get the size of the flows vector.
     * @return The size of the flows vector.
     */
    virtual int flowsSize() = 0;

    /**
     * @brief Get the size of the systems vector.
     * @return The size of the systems vector.
     */
    virtual int systemsSize() = 0;

    /**
     * @brief Set the name of the model.
     * @param name The name of the model.
     */
    virtual void setName(string) = 0;

    /**
     * @brief Get the name of the model.
     * @return The name of the model.
     */
    virtual string getName() const = 0;

    /**
     * @brief Add a System object to the model.
     * @param system The System object to be added.
     * @return True if the addition was successful, false otherwise.
     */
    virtual bool add(System*) = 0;

    /**
     * @brief Add a Flow object to the model.
     * @param flow The Flow object to be added.
     * @return True if the addition was successful, false otherwise.
     */
    virtual bool add(Flow*) = 0;

    /**
     * @brief Remove a System object from the model.
     * @param system The System object to be removed.
     * @return True if the removal was successful, false otherwise.
     */
    virtual bool remove(System*) = 0;

    /**
     * @brief Remove a Flow object from the model.
     * @param flow The Flow object to be removed.
     * @return True if the removal was successful, false otherwise.
     */
    virtual bool remove(Flow*) = 0;

    /**
     * @brief Run the model for a specified number of iterations.
     * @param t_begin The number of iterations to run.
     * @param t_end The time step for each iteration.
     * @return True if the model ran successfully, false otherwise.
     */
    virtual bool run(int, int) = 0;

    /**
     * @brief Print a summary of the model's systems and flows.
     */
    //virtual void summary() = 0;
};

#endif