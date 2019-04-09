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

void StateService::updateState(int deviceId, double measurementValue){
    this->state[deviceId] = measurementValue;
}

double StateService::getValue(int deviceId){
    if(this->state.find(deviceId) == this->state.end())
        return 0.0;
    else return this->state[deviceId];
}

}