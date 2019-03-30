#include<string>
#include<boost/python.hpp>

#include"controllers/MeasurementController.hpp"
#include"services/PostgreSQLService.hpp"
#include"services/DatabaseService.hpp"

namespace zpr {

MeasurementController::MeasurementController() {}

std::string MeasurementController::postNewMeasurement(boost::python::dict& request){
    std::string returnMessage;

    std::shared_ptr<DatabaseService> db = std::make_shared<PostgreSQLService>("localhost", "zpr", "zpr", "5432");
    db->doWork("SELECT * FROM measurements WHERE device_id=2 order by timestamp desc");
    
    if(request.has_key("firstarg")) {
        boost::python::object message = request.get("firstarg");
        returnMessage = boost::python::extract<std::string>(message);
    }
    else   
        returnMessage = std::string("OK");
    return returnMessage;
}

}