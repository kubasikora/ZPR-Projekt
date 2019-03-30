#include"controllers/MeasurementController.hpp"
#include<string>

#include<boost/python.hpp>

namespace zpr {

MeasurementController::MeasurementController() {}

std::string MeasurementController::postNewMeasurement(boost::python::dict& request){
    std::string returnMessage;
    if(request.has_key("firstarg")) {
        boost::python::object message = request.get("firstarg");
        returnMessage = boost::python::extract<std::string>(message);
    }
    else   
        returnMessage = std::string("OK");

    return returnMessage;
}

}