#ifndef __MEASUREMENT_CONTROLLER_H_
#define __MEASUREMENT_CONTROLLER_H_

#include<string>
#include<boost/python.hpp>

namespace zpr {

class MeasurementController {
  public:
    MeasurementController();
    std::string postNewMeasurement(boost::python::dict& request);
};

}
#endif //__MEASUREMENT_CONTROLLER_H_
