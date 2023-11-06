#include "model.h"


Model :: Model(string nome){
    this->name = name;
}

Model :: Model(const Model &model){
    name = model.getName();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());
}

Model& Model :: operator=(const Model &model){
    if(this == &model)
        return *this;

    name = model.getName();
    
    systems.clear();
    systems.insert(systems.begin(), model.systems.begin(), model.systems.end());

    flows.clear();
    flows.insert(flows.begin(), model.flows.begin(), model.flows.end());

    return *this;
}

Model :: ~Model(){}

Model :: systemsIterator Model :: systemsBegin(){
    return systems.begin();
}

Model :: systemsIterator Model :: systemsEnd(){
    return systems.end();
}

Model :: flowsIterator Model :: flowsBegin(){
    return flows.begin();
}

Model :: flowsIterator Model :: flowsEnd(){
    return flows.end();
}

void Model :: setName(string name){
    this->name = name;
}

string Model :: getName() const{
    return name;
}

bool Model :: add(System *system){
    long unsigned int size = systems.size();
    systems.push_back(system);

    return (size != systems.size());
}

bool Model :: add(Flow *flow){
    long unsigned int size = flows.size();
    flows.push_back(flow);

    return (size != flows.size());
}

bool Model :: remove(System *system){
    for (systemsIterator i = systemsBegin(); i < systemsEnd(); i++){
        if(*i == system){
            systems.erase(i);
            return true;
        }
    }
    return false;
}

bool Model :: remove(Flow *flow){
    for (flowsIterator i = flowsBegin(); i < flowsEnd(); i++){
        if(*i == flow){
            flows.erase(i);
            return true;
        }
    }
    return false;
}


bool Model :: run(int t_begin, int t_end){
    if(t_begin < 0 || t_end < 0 || t_begin > t_end)
        return false;


    double values[flows.size()] = {};

    for (int i = t_begin; i <= t_end; i++){
       
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

void Model :: summary(){
    
    cout << "------------------------------" << endl;

    cout << "\nModel Summary" << endl;

    for(System *system : this->systems){
        cout << *system << endl;
    }

    cout << "------------------------------" << endl;
}