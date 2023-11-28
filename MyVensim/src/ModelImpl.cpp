#include "ModelImpl.hpp"


vector<Model*> ModelImpl :: models;

ModelImpl :: ModelImpl(const ModelImpl &model){
    name = model.getName();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
}

ModelImpl& ModelImpl :: operator=(const ModelImpl &model){
    if(this == &model)
        return *this;

    name = model.getName();
    
    systems.clear();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());

    flows.clear();
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());

    return *this;
}

ModelImpl :: ModelImpl(){
    name = "";
}

ModelImpl :: ModelImpl(string name){
    this->name = name;
}

ModelImpl :: ~ModelImpl(){
    
    systemsIterator sysIt = systemsBegin();
    while(sysIt != systemsEnd()){
        delete *sysIt;
        sysIt++;
    }

    systems.clear();

    flowsIterator flowIt = flowsBegin();
    while(flowIt != flowsEnd()){
        delete *flowIt;
        flowIt++;
    }

    flows.clear();

    modelsIterator modelsIt = modelsBegin();
    while(modelsIt != modelsEnd()){
        if(*modelsIt == this){
            models.erase(modelsIt);
            break;
        }
    }

    models.clear();
}

ModelImpl :: systemsIterator ModelImpl :: systemsBegin(){
    return systems.begin();
}

ModelImpl :: systemsIterator ModelImpl :: systemsEnd(){
    return systems.end();
}

int ModelImpl :: systemsSize(){
    return systems.size();
}

ModelImpl :: flowsIterator ModelImpl :: flowsBegin(){
    return flows.begin();
}

ModelImpl :: flowsIterator ModelImpl :: flowsEnd(){
    return flows.end();
}

int ModelImpl :: flowsSize(){
    return flows.size();
}

ModelImpl :: modelsIterator ModelImpl :: modelsBegin(){
    return models.begin();
}

ModelImpl :: modelsIterator ModelImpl :: modelsEnd(){
    return models.end();
}

int ModelImpl :: modelsSize(){
    return models.size();
}

Model& Model :: createModel(string name){
    return ModelImpl::createModel(name);
}

Model& ModelImpl :: createModel(string name){
    Model *model = new ModelImpl(name);
    models.push_back(model);
    return *model;
}

Model& Model :: createModel(){
    return ModelImpl::createModel();
}

Model& ModelImpl :: createModel(){
    Model *model = new ModelImpl();
    models.push_back(model);
    return *model;
}

System& ModelImpl :: createSystem(string name, double value){
    System* system = new SystemImpl(name, value);
    add(system);
    return *system;
}

System& ModelImpl :: createSystem(){
    System* system = new SystemImpl();
    add(system);
    return *system;
}

void ModelImpl :: setName(string name){
    this->name = name;
}

string ModelImpl :: getName() const{
    return name;
}

bool ModelImpl :: add(System *system){
    long unsigned int size = systems.size();
    systems.push_back(system);

    return (size != systems.size());
}

bool ModelImpl :: add(Flow *flow){
    long unsigned int size = flows.size();
    flows.push_back(flow);

    return (size != flows.size());
}

bool ModelImpl :: add(Model *model){
    long unsigned int size = models.size();
    models.push_back(model);

    return (size != models.size());
}

bool ModelImpl :: remove(System *system){
    for (systemsIterator i = systemsBegin(); i < systemsEnd(); i++){
        if(*i == system){
            systems.erase(i);
            return true;
        }
    }

    return false;
}

bool ModelImpl :: remove(Flow *flow){
    for (flowsIterator i = flowsBegin(); i < flowsEnd(); i++){
        if(*i == flow){
            flows.erase(i);
            return true;
        }
    }
    return false;
}

bool ModelImpl :: remove(Model *model){
    for (modelsIterator i = modelsBegin(); i < modelsEnd(); i++){
        if(*i == model){
            models.erase(i);
            return true;
        }
    }
    return false;
}

int ModelImpl :: run(int t_begin, int t_end){
    if(t_begin < 0 || t_end < 0 || t_begin > t_end)
        return -1;


    double values[flows.size()] = {};

    int i;
    for (i = t_begin; i < t_end; i++){
       
        flowsIterator it = flowsBegin();
        for (long unsigned int j = 0; j < flows.size(); j++){
            values[j] = (*it)->executeFunction();
            it++;
        }

        it = flowsBegin();
        System *begin, *end;
        for (long unsigned int k = 0; k < flows.size(); k++){
            begin = (*it)->getBegin();
            begin->setValue(begin->getValue() - values[k]);

            end = (*it)->getEnd();
            end->setValue(end->getValue() + values[k]);

            it++;
        }
    }

    return i;
    
}

void ModelImpl :: summary(){
    cout << "Model Summary\n" << endl;

    cout << name << endl;
    
    cout << "------------------------------" << endl;


    for(System *system : this->systems){
        cout << "\nName:" << system->getName() << endl;
        cout << "Value:" << system->getValue() << endl;
    }

    cout << "------------------------------" << endl;
}