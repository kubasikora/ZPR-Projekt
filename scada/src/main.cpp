#include<iostream>
#include<boost/python.hpp>

#include"controllers/MeasurementController.hpp"
#include"controllers/SerializeDataController.hpp"
#include"controllers/StateController.hpp"

void initModule() {

}

BOOST_PYTHON_MODULE(libscada) {
    initModule();

    boost::python::class_<zpr::MeasurementController>("MeasurementController", boost::python::init<boost::python::dict&>())
    .def("postNewMeasurement", &zpr::MeasurementController::postNewMeasurement)
    .def("getStatusCode", &zpr::MeasurementController::getStatusCode);

    boost::python::class_<zpr::SerializeDataController>("SerializeDataController", boost::python::init<boost::python::dict&>())
    .def("getSerializedData", &zpr::SerializeDataController::getSerializedData)
    .def("getStatusCode", &zpr::SerializeDataController::getStatusCode);

    boost::python::class_<zpr::StateController>("StateController")
    .def("getState", &zpr::StateController::getState)
    .def("getStatusCode", &zpr::SerializeDataController::getStatusCode);

}