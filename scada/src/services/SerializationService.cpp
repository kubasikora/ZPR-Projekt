#include<vector>
#include<memory>
#include<pqxx/pqxx>
#include<iostream>
#include"services/SerializationService.hpp"
#include"mappers/Measurement.hpp"
#include<string>

namespace zpr {

const int SerializationService::maxSamples = 100;

    

boost::python::dict SerializationService::mapToPythonDict(std::unique_ptr<std::vector<Measurement>> measurements){
    boost::python::dict result;
    boost::python::list list;
    measurements = this->resample(std::move(measurements));
    for(auto it = measurements->begin(); it != measurements->end(); ++it) {
        boost::python::dict data;
        data["value"] = it->getValue();
        data["timestamp"] = it->getTimestamp();
        list.append(data);
    }

    int deviceId;
    deviceId = measurements->at(0).getDeviceId();
    result["deviceId"] = deviceId;
    result["data"] = list;
    return result;
}


std::unique_ptr<std::vector<Measurement>> SerializationService::resample(std::unique_ptr<std::vector<Measurement>> measurements){
    if(!(measurements->size() <= this->maxSamples)){
        float freq;
        std::unique_ptr<std::vector<Measurement>> resampledMeasurements = std::make_unique<std::vector<Measurement>>();
        freq = floor(measurements->size()/this->maxSamples);

        for (int i = 1; i <= maxSamples; ++i){
            resampledMeasurements->push_back(measurements->at(i*freq));
        }
        return resampledMeasurements;
    }
    else
        return measurements;
}

}