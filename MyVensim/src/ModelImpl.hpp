#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "Model.hpp"

using namespace std;

/**
 * @brief Implementation of the Model class.
 */
class ModelImpl : public Model {
protected:
    string name; ///< @brief Name of the model.
    vector<System*> systems; ///< @brief Vector to store System objects.
    vector<Flow*> flows; ///< @brief Vector to store Flow objects.
    static vector<Model*> models; ///< @brief Vector to store sub-models.

    /**
     * @brief Add a System object to the model.
     * @param system The System object to be added.
     * @return True if the addition was successful, false otherwise.
     */
    bool add(System*);

    /**
     * @brief Add a Flow object to the model.
     * @param flow The Flow object to be added.
     * @return True if the addition was successful, false otherwise.
     */
    bool add(Flow*);

    /**
     * @brief Add a sub-model to the model.
     * @param model The Model object to be added.
     * @return True if the addition was successful, false otherwise.
     */
    bool add(Model*);

private:
    /**
     * @brief Copy constructor for Model.
     * @param model The Model object to be copied.
     */
    ModelImpl(const ModelImpl&);

    /**
     * @brief Assignment operator overload.
     * @param model The Model object to be assigned.
     * @return A reference to the current Model object.
     */
    ModelImpl& operator=(const ModelImpl&);

public:
    /**
     * @brief Default constructor for the ModelImpl class.
     */
    ModelImpl();

    /**
     * @brief Constructor that initializes a Model with a name.
     * @param name The name of the model.
     */
    ModelImpl(string name);

    /**
     * @brief Destructor for the ModelImpl class.
     */
    virtual ~ModelImpl();

    /**
     * @brief Get an iterator pointing to the beginning of the systems vector.
     * @return An iterator to the beginning of the systems vector.
     */
    systemsIterator systemsBegin();

    /**
     * @brief Get an iterator pointing to the end of the systems vector.
     * @return An iterator to the end of the systems vector.
     */
    systemsIterator systemsEnd();

    /**
     * @brief Get the size of the systems vector.
     * @return The size of the systems vector.
     */
    int systemsSize();

    /**
     * @brief Get an iterator pointing to the beginning of the flows vector.
     * @return An iterator to the beginning of the flows vector.
     */
    flowsIterator flowsBegin();

    /**
     * @brief Get an iterator pointing to the end of the flows vector.
     * @return An iterator to the end of the flows vector.
     */
    flowsIterator flowsEnd();

    /**
     * @brief Get the size of the flows vector.
     * @return The size of the flows vector.
     */
    int flowsSize();

    /**
     * @brief Get an iterator pointing to the beginning of the models vector.
     * @return An iterator to the beginning of the models vector.
     */
    modelsIterator modelsBegin();

    /**
     * @brief Get an iterator pointing to the end of the models vector.
     * @return An iterator to the end of the models vector.
     */
    modelsIterator modelsEnd();

    /**
     * @brief Get the size of the models vector.
     * @return The size of the models vector.
     */
    int modelsSize();

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
    System& createSystem(string, double);

    /**
     * @brief Create and return an instance of the System class with default values.
     * @return A reference to the created System object.
     */
    System& createSystem();

    /**
     * @brief Set the name of the model.
     * @param name The name of the model.
     */
    void setName(string);

    /**
     * @brief Get the name of the model.
     * @return The name of the model.
     */
    string getName() const;

    /**
     * @brief Remove a System object from the model.
     * @param system The System object to be removed.
     * @return True if the removal was successful, false otherwise.
     */
    bool remove(System*);

    /**
     * @brief Remove a Flow object from the model.
     * @param flow The Flow object to be removed.
     * @return True if the removal was successful, false otherwise.
     */
    bool remove(Flow*);

    /**
     * @brief Remove a sub-model from the model.
     * @param model The Model object to be removed.
     * @return True if the removal was successful, false otherwise.
     */
    bool remove(Model*);

    /**
     * @brief Run the model for a specified number of iterations.
     * @param t_begin The number of iterations to run.
     * @param t_end The time step for each iteration.
     * @return The number of iterations in the model.
     */
    int run(int, int);

    /**
     * @brief Print a summary of the model's systems, flows, and sub-models.
     */
    void summary();
};

#endif
