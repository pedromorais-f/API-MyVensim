#include "ModelImpl.hpp"

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

ModelImpl :: ~ModelImpl(){}

ModelImpl :: systemsIterator ModelImpl :: systemsBegin(){
    return systems.begin();
}

ModelImpl :: systemsIterator ModelImpl :: systemsEnd(){
    return systems.end();
}

ModelImpl :: flowsIterator ModelImpl :: flowsBegin(){
    return flows.begin();
}

ModelImpl :: flowsIterator ModelImpl :: flowsEnd(){
    return flows.end();
}

void ModelImpl :: setName(string name){
    this->name = name;
}

int ModelImpl :: flowsSize(){
    return flows.size();
}
int ModelImpl :: systemsSize(){
    return systems.size();
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

bool ModelImpl :: run(int t_begin, int t_end){
    if(t_begin < 0 || t_end < 0 || t_begin > t_end)
        return false;


    double values[flows.size()] = {};

    for (int i = t_begin; i < t_end; i++){
       
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

    return true;
    
}

void ModelImpl :: summary(){
    cout << "Model Summary\n" << endl;

    cout << name << endl;
    
    cout << "------------------------------" << endl;


    for(System *system : this->systems)
        cout << "\n" << *dynamic_cast<SystemImpl*>(system) << endl;

    cout << "------------------------------" << endl;
}