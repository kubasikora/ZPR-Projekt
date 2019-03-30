#ifndef __MEASUREMENT_CONTROLLER_HPP_
#define __MEASUREMENT_CONTROLLER_HPP_

#include<string>
#include<boost/python.hpp>

namespace zpr {

class MeasurementController {
  public:
    MeasurementController(boost::python::dict& env);
    std::string postNewMeasurement(boost::python::dict& request);
  
  private:
    std::string host;
    std::string user;
    std::string password;
    std::string port;
};

}
#endif //__MEASUREMENT_CONTROLLER_HPP_
