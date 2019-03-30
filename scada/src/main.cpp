#include<boost/python.hpp>
#include"foo.h"
#include"controllers/MeasurementController.hpp"
#include<iostream>


void initModule(){

}

BOOST_PYTHON_MODULE(libscada) {
    initModule();

    boost::python::class_<zpr::MeasurementController>("MeasurementController")
    .def("postNewMeasurement", &zpr::MeasurementController::postNewMeasurement);
}