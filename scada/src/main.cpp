#include<boost/python.hpp>
#include"foo.h"
#include"MeasurementController.hpp"
#include<iostream>


void initModule(){

}

BOOST_PYTHON_MODULE(libscada) {
    initModule();
    //boost::python::def("foo", zpr::foo);
    //boost::python::def("getData", zpr::getData);
    boost::python::class_<zpr::MeasurementController>("MeasurementController")
    .def("postNewMeasurement", &zpr::MeasurementController::postNewMeasurement);
}

/*
int main(){
    std::cout <<  << std::endl;
    return 0;
}
*/
