#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Flow.hpp"
#include "FlowImpl.hpp"

/**
 * @brief Abstract base class representing a model with systems, flows, and sub-models.
 */
class Model {
public:
    /**
     * @brief Virtual destructor for the Model class.
     */
    virtual ~Model() {};

    typedef vector<System*>::iterator systemsIterator; ///< @brief Iterator for the systems vector.
    typedef vector<Flow*>::iterator flowsIterator; ///< @brief Iterator for the flows vector.
    typedef vector<Model*>::iterator modelsIterator; ///< @brief Iterator for the models vector.

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
     * @brief Get the size of the systems vector.
     * @return The size of the systems vector.
     */
    virtual int systemsSize() = 0;

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
     * @brief Get an iterator pointing to the beginning of the models vector.
     * @return An iterator to the beginning of the models vector.
     */
    virtual modelsIterator modelsBegin() = 0;

    /**
     * @brief Get an iterator pointing to the end of the models vector.
     * @return An iterator to the end of the models vector.
     */
    virtual modelsIterator modelsEnd() = 0;

    /**
     * @brief Get the size of the models vector.
     * @return The size of the models vector.
     */
    virtual int modelsSize() = 0;

    /**
     * @brief Create and return an instance of the Model class.
     * @param name The name of the model.
     * @return A reference to the created Model object.
     */
    static Model& createModel(string);

    /**
     * @brief Create and return an instance of the Model class with a default name.
     * @return A reference to the created Model object.
     */
    static Model& createModel();

    /**
     * @brief Create and return an instance of the System class.
     * @param name The name of the system.
     * @param value The initial value of the system.
     * @return A reference to the created System object.
     */
    virtual System& createSystem(string, double) = 0;

    /**
     * @brief Create and return an instance of the System class with default values.
     * @return A reference to the created System object.
     */
    virtual System& createSystem() = 0;

    /**
     * @brief Create and return an instance of the Flow class.
     * @tparam TYPE The type of Flow to be created.
     * @param begin The starting system of the flow.
     * @param end The ending system of the flow.
     * @return A reference to the created Flow object.
     */
    template <typename TYPE>
    Flow& createFlow(System *begin = nullptr, System *end = nullptr) {
        Flow* flow = new FlowHandle<TYPE>(begin, end);
        add(flow);
        return *flow;
    }

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
     * @brief Add a sub-model to the model.
     * @param model The Model object to be added.
     * @return True if the addition was successful, false otherwise.
     */
    virtual bool add(Model*) = 0;

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
     * @brief Remove a sub-model from the model.
     * @param model The Model object to be removed.
     * @return True if the removal was successful, false otherwise.
     */
    virtual bool remove(Model*) = 0;

    /**
     * @brief Run the model for a specified number of iterations.
     * @param t_begin The number of iterations to run.
     * @param t_end The time step for each iteration.
     * @return The number of iterations in the model.
     */
    virtual int run(int, int) = 0;

    /**
     * @brief Print a summary of the model's systems, flows, and sub-models.
     */
    virtual void summary() = 0;
};

#endif