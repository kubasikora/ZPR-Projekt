#include<string>
#include<stdexcept>
#include<vector>

#include"controllers/SerializeDataController.hpp"
#include"controllers/DatabaseController.hpp"
#include"services/PostgreSQLService.hpp"
#include"utilities/utilities.hpp"
#include"mappers/Measurement.hpp"
#include"services/SerializationService.hpp"

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>

namespace zpr {

boost::python::dict SerializeDataController::getSerializedData(boost::python::dict& arguments) {
    try {
        std::unique_ptr<std::vector<std::string>> dbResultSet = std::make_unique<std::vector<std::string>>();
        boost::python::dict result;

        std::unique_ptr<DatabaseService> db = std::make_unique<PostgreSQLService>(this->host, this->user, this->password, this->port);
        dbResultSet = db->doWork(Measurement::mapEntityToSQLSelect(arguments));
        
        std::unique_ptr<std::vector<Measurement>>measurementSet = std::make_unique<std::vector<Measurement>>();
        measurementSet = Measurement::mapToMeasurements(std::move(dbResultSet));
    
        SerializationService serializationService;
        result = serializationService.mapToPythonDict(std::move(measurementSet));


        this->statusCode = 201;
        return result;
    }
    catch(KeyDoNotExistsException& ex) {
        boost::python::dict returnMessage;
        returnMessage["returnMessage"] = "Missing key " + ex.key;
        this->statusCode = 400;
        return returnMessage;
    }
    catch(std::invalid_argument& ex) {
        boost::python::dict returnMessage;
        returnMessage["returnMessage"] = "Invalid key";
        this->statusCode = 400;
        return returnMessage;
    }
    catch(ForeignKeyViolationException& ex) {
        boost::python::dict returnMessage;
        returnMessage["returnMessage"] =  "Nonexisting device";
        this->statusCode = 400;
        return returnMessage;
    }
}


}