#include<memory>
#include<map>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include"services/StateService.hpp"

namespace zpr {

StateService* StateService::instance = nullptr;

StateService* StateService::getInstance() {
    if(!instance) {
        Lock guard(std::mutex());

        if(!instance) {
            instance = new StateService();
        }
    }

    return instance;
}

void StateService::updateState(const int deviceId, const double measurementValue) {
    this->state[deviceId] = measurementValue;
}

double StateService::getValue(const int deviceId) {
    if(this->state.find(deviceId) == this->state.end())
        return 0.0;
    else return this->state[deviceId];
}

boost::python::list StateService::mapToPythonList() {
    Lock guard(std::mutex());
    boost::python::list deviceList;

    for(auto it = state.begin(); it != state.end(); ++it) {
        boost::python::dict dictionary;
        dictionary["deviceId"] = it->first;
        dictionary["value"] = it->second;
        deviceList.append(dictionary);
    }

    return deviceList;
}

}