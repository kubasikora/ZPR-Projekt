#include<string>
#include<stdexcept>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>

#include"controllers/MeasurementController.hpp"
#include"services/PostgreSQLService.hpp"
#include"services/StateService.hpp"
#include"mappers/Measurement.hpp"

#include"utilities/utilities.hpp"

namespace zpr {

std::string MeasurementController::postNewMeasurement(boost::python::dict& request) {
    try {
        Measurement newMeasurement(request);

        std::unique_ptr<DatabaseService> db = std::make_unique<PostgreSQLService>(this->host, this->user, this->password, this->port);
        db->doWork(newMeasurement.mapEntityToSQLInsert());

        StateService* state = StateService::getInstance();
        state->updateState(newMeasurement.getDeviceId(), newMeasurement.getValue());

        this->statusCode = 201;
        return std::string("OK");
    }
    catch(KeyDoNotExistsException& ex) {
        std::string returnMessage = "Missing key " + ex.key;
        this->statusCode = 400;
        return returnMessage;
    }
    catch(std::invalid_argument& ex) {
        std::string returnMessage = "Invalid key";
        this->statusCode = 400;
        return returnMessage;
    }
    catch(ForeignKeyViolationException& ex) {
        std::string returnMessage = "Nonexisting device";
        this->statusCode = 400;
        return returnMessage;
    }
}

}