#include<string>
#include<boost/python.hpp>
#include<iostream>

#include"controllers/MeasurementController.hpp"
#include"services/PostgreSQLService.hpp"
#include"services/DatabaseService.hpp"
#include"mappers/Measurement.hpp"

#include"utilities/utilities.hpp"

namespace zpr {

MeasurementController::MeasurementController(boost::python::dict& env) {
   this->host = extractKeyFromPythonDict(env, "host");
   this->user = extractKeyFromPythonDict(env, "user");
   this->password = extractKeyFromPythonDict(env, "password");
   this->port = extractKeyFromPythonDict(env, "port");
}

std::string MeasurementController::postNewMeasurement(boost::python::dict& request){
    Measurement newMeasurement(request);

    std::shared_ptr<DatabaseService> db = std::make_shared<PostgreSQLService>(this->host, this->user, this->password, this->port);
    db->doWork(newMeasurement.mapEntityToSQLInsert());

    return std::string("OK");
}

}