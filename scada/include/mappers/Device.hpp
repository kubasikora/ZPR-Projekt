#ifndef __DEVICE_HPP_
#define __DEVICE_HPP_

#include<boost/python.hpp>
#include<string>
#include"mappers/Entity.hpp"

namespace zpr {

class Device : public Entity {
  public:
    Device();
    Device(const std::string id, const std::string serialCode, const std::string model, const std::string producer, const std::string unit, const std::string minValue, const std::string maxValue);
    Device(const boost::python::dict& deviceModel);
  private:
    static const std::string tableName;
    std::string serialCode;
    std::string model;
    std::string producer;
    std::string unit;
    double minValue;
    double maxValue;
};

}

#endif //__DEVICE_HPP