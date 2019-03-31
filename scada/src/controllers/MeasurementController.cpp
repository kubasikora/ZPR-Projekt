#include<string>
#include<boost/python.hpp>

#include"controllers/MeasurementController.hpp"
#include"services/PostgreSQLService.hpp"
#include"services/DatabaseService.hpp"
#include"mappers/Measurement.hpp"

#include"utilities/utilities.hpp"

namespace zpr {

std::string MeasurementController::postNewMeasurement(boost::python::dict& request){
    try{
        Measurement newMeasurement(request);

        std::shared_ptr<DatabaseService> db = std::make_shared<PostgreSQLService>(this->host, this->user, this->password, this->port);
        db->doWork(newMeasurement.mapEntityToSQLInsert());

        return std::string("OK");
    }
    catch(KeyDoNotExistsException& ex){
        std::string returnMessage = "Missing key " + ex.key;
        return returnMessage;
    }
}

}