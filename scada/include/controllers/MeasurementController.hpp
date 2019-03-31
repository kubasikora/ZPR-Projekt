#ifndef __MEASUREMENT_CONTROLLER_HPP_
#define __MEASUREMENT_CONTROLLER_HPP_

#include<string>
#include<boost/python.hpp>

#include"controllers/DatabaseController.hpp"

namespace zpr {

class MeasurementController : private DatabaseController {
  public:
    MeasurementController(boost::python::dict& env) : DatabaseController(env) {}
    std::string postNewMeasurement(boost::python::dict& request);
};

}
#endif //__MEASUREMENT_CONTROLLER_HPP_
