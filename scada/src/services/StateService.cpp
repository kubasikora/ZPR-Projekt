#include<memory>
#include<map>

#include"services/StateService.hpp"

namespace zpr {

StateService* StateService::instance = nullptr;

StateService* StateService::getInstance() {
    if(!instance){
        Lock guard(std::mutex());
        if(!instance) {
            instance = new StateService();
        }
    }
    return instance;
}

void StateService::updateState(const int deviceId, const double measurementValue){
    this->state[deviceId] = measurementValue;
}

double StateService::getValue(const int deviceId){
    if(this->state.find(deviceId) == this->state.end())
        return 0.0;
    else return this->state[deviceId];
}

boost::python::dict StateService::mapToPythonDict(){
    Lock guard(std::mutex());
    boost::python::dict dictionary;
    for(auto it = state.begin(); it != state.end(); ++it){
        dictionary[it->first] = it->second;
    }
    return dictionary;
}

}