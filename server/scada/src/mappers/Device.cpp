#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<string>
#include<sstream>

#include"mappers/Device.hpp"
#include"utilities/utilities.hpp"


namespace zpr {

const std::string Device::tableName = "devices";

Device::Device() : Entity(0) {

}

Device::Device(const std::string id,
               const std::string serialCode,
               const std::string model,
               const std::string producer,
               const std::string unit,
               const std::string minValue,
               const std::string maxValue) : Entity(std::stoi(id)) {
    this->serialCode = serialCode;
    this->model = model;
    this->producer = producer;
    this->unit = unit;
    this->minValue = std::stod(minValue);
    this->maxValue = std::stod(maxValue);
}

Device::Device(const boost::python::dict& deviceModel) : Entity(std::stoi(extractKeyFromPythonDict(deviceModel, "deviceId"))) {
    this->id = std::stoi(extractKeyFromPythonDict(deviceModel, "deviceId"));
    this->serialCode = extractKeyFromPythonDict(deviceModel, "serialCode");
    this->model = extractKeyFromPythonDict(deviceModel, "model");
    this->producer = extractKeyFromPythonDict(deviceModel, "producer");
    this->unit = extractKeyFromPythonDict(deviceModel, "unit");
    this->minValue = std::stoi(extractKeyFromPythonDict(deviceModel, "minValue"));
    this->maxValue = std::stoi(extractKeyFromPythonDict(deviceModel, "maxValue"));
}

}