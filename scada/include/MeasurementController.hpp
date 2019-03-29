#ifndef __MEASUREMENT_CONTROLLER_H_
#define __MEASUREMENT_CONTROLLER_H_

#include<string>
#include<boost/python.hpp>

namespace zpr {

class MeasurementController{
  public:
    MeasurementController();
    std::string postNewMeasurement();
};

}
#endif //__MEASUREMENT_CONTROLLER_H_
