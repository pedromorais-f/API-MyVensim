#include "ModelImpl.hpp"
#include "SystemImpl.hpp"
#include "FlowImpl.hpp"


vector<Model*> ModelBody :: models;

ModelBody :: ModelBody(){
    name = "";
}

ModelBody :: ModelBody(string name){
    this->name = name;
}

ModelBody :: ~ModelBody(){
    Model :: systemsIterator sysIt = systemsBegin();
    while(sysIt != systemsEnd()){
        delete *sysIt;
        sysIt++;
    }

    Model :: flowsIterator flowIt = flowsBegin();
    while(flowIt != flowsEnd()){
        delete *flowIt;
        flowIt++;
    }
}

ModelBody :: ModelBody(const ModelBody &model){
    name = model.getName();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
}

ModelBody& ModelBody :: operator=(const ModelBody &model){
    if(this == &model)
        return *this;

    name = model.getName();
    
    systems.clear();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());

    flows.clear();
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());

    return *this;
}

Model :: systemsIterator ModelBody :: systemsBegin(){
    return systems.begin();
}

Model :: systemsIterator ModelBody :: systemsEnd(){
    return systems.end();
}

int ModelBody :: systemsSize(){
    return systems.size();
}

Model :: flowsIterator ModelBody :: flowsBegin(){
    return flows.begin();
}

Model :: flowsIterator ModelBody :: flowsEnd(){
    return flows.end();
}

int ModelBody :: flowsSize(){
    return flows.size();
}

Model :: modelsIterator ModelBody :: modelsBegin(){
    return models.begin();
}

Model :: modelsIterator ModelBody :: modelsEnd(){
    return models.end();
}

int ModelBody :: modelsSize(){
    return models.size();
}

void ModelBody :: erase(Model :: modelsIterator it){
    models.erase(it);
}

Model& Model :: createModel(){
    return ModelBody::createModel();
}

Model& ModelBody :: createModel(){
    Model *model = new ModelHandle();
    models.push_back(model);
    return *model;
}

Model& Model :: createModel(string name){
    return ModelBody::createModel(name);
}

Model& ModelBody :: createModel(string name){
    Model *model = new ModelHandle(name);
    models.push_back(model);
    return *model;
}


System& ModelBody :: createSystem(string name, double value){
    System* system = new SystemHandle(name, value);
    add(system);
    return *system;
}

System& ModelBody :: createSystem(){
    System* system = new SystemHandle();
    add(system);
    return *system;
}

void ModelBody :: setName(string name){
    this->name = name;
}

string ModelBody :: getName() const{
    return name;
}

bool ModelBody :: add(System *system){
    long unsigned int size = systems.size();
    systems.push_back(system);

    return (size != systems.size());
}

bool ModelBody :: add(Flow *flow){
    long unsigned int size = flows.size();
    flows.push_back(flow);

    return (size != flows.size());
}

bool ModelBody :: add(Model *model){
    long unsigned int size = models.size();
    models.push_back(model);

    return (size != models.size());
}

bool ModelBody :: remove(System *system){
    for (Model :: systemsIterator i = systemsBegin(); i < systemsEnd(); i++){
        if(*i == system){
            systems.erase(i);
            return true;
        }
    }

    return false;
}

bool ModelBody :: remove(Flow *flow){
    for (Model :: flowsIterator i = flowsBegin(); i < flowsEnd(); i++){
        if(*i == flow){
            flows.erase(i);
            return true;
        }
    }
    return false;
}

bool ModelBody :: remove(Model *model){
    for (Model :: modelsIterator i = modelsBegin(); i < modelsEnd(); i++){
        if(*i == model){
            models.erase(i);
            return true;
        }
    }
    return false;
}

int ModelBody :: run(int t_begin, int t_end){
    if(t_begin < 0 || t_end < 0 || t_begin > t_end)
        return -1;


    double values[flows.size()] = {};

    int i;
    for (i = t_begin; i < t_end; i++){
       
        Model :: flowsIterator it = flowsBegin();
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

void ModelBody :: summary(){
    cout << "Model Summary\n" << endl;

    cout << name << endl;
    
    cout << "------------------------------" << endl;


    for(System *system : this->systems){
        cout << "\nName:" << system->getName() << endl;
        cout << "Value:" << system->getValue() << endl;
    }

    cout << "------------------------------" << endl;
}