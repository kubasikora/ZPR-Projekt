#include<iostream>
#include<boost/python.hpp>

#include"controllers/MeasurementController.hpp"

void initModule(){

}

BOOST_PYTHON_MODULE(libscada) {
    initModule();

    boost::python::class_<zpr::MeasurementController>("MeasurementController", boost::python::init<boost::python::dict&>())
    .def("postNewMeasurement", &zpr::MeasurementController::postNewMeasurement)
    .def("getStatusCode", &zpr::MeasurementController::getStatusCode);
}