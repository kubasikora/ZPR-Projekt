#include<string>
#include<boost/python.hpp>

#include"controllers/MeasurementController.hpp"
#include"services/PostgreSQLService.hpp"
#include"services/DatabaseService.hpp"

#include"utilities/utilities.hpp"

namespace zpr {

MeasurementController::MeasurementController(boost::python::dict& env) {
   this->host = extractKeyFromPythonDict(env, "host");
   this->user = extractKeyFromPythonDict(env, "user");
   this->password = extractKeyFromPythonDict(env, "password");
   this->port = extractKeyFromPythonDict(env, "port");
}

std::string MeasurementController::postNewMeasurement(boost::python::dict& request){
    std::shared_ptr<DatabaseService> db = std::make_shared<PostgreSQLService>(this->host, this->user, this->password, this->port);
    db->doWork("SELECT * FROM measurements WHERE device_id=2 order by timestamp desc");
    
    std::string returnMessage = extractKeyFromPythonDict(request, "arg");
    if(!returnMessage.compare(std::string(""))) returnMessage = "OK";

    return returnMessage;
}

}