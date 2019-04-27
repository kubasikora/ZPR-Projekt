#ifndef __MEASUREMENT_CONTROLLER_HPP_
#define __MEASUREMENT_CONTROLLER_HPP_

#include<string>
#include<boost/python.hpp>

#include"controllers/DatabaseController.hpp"
#include"controllers/RESTServiceController.hpp"

namespace zpr {

class MeasurementController : public DatabaseController, public RESTServiceController {
    public:
        MeasurementController(boost::python::dict& env) : DatabaseController(env) {}
        std::string postNewMeasurement(boost::python::dict& request);
};

}
#endif //__MEASUREMENT_CONTROLLER_HPP_
