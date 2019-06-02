#include"mappers/Measurement.hpp"
#include"utilities/utilities.hpp"
#include<string>
#include<sstream>

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/date_time.hpp>


namespace zpr {

const std::string Measurement::tableName = "measurements";

Measurement::Measurement() : Entity(0) {

}

Measurement::Measurement(const std::string id,
                         const std::string value,
                         const std::string timestamp,
                         const std::string deviceId) : Entity(std::stoi(id)) {
    std::string tstmp = timestamp;
    this->value = std::stod(value);
    this->timestamp = timestampToPTime(validateDateFormat(tstmp));
    this->deviceId = std::stoi(deviceId);
}


Measurement::Measurement(const boost::python::dict& request) : Entity(0) {
    this->value = std::stod(extractKeyFromPythonDict(request, "value").c_str());
    this->deviceId = std::stoi(extractKeyFromPythonDict(request, "deviceId").c_str());
    this->timestamp = boost::posix_time::second_clock::local_time();
}

const std::string Measurement::mapEntityToSQLInsert() const {
    std::string sql = "INSERT INTO ";
    sql+= this->tableName;
    sql+= " VALUES (default, ";
    sql+= std::to_string(this->value);
    sql+= ", TIMESTAMP '";
    sql+= pTimeToTimestamp(this->timestamp);
    sql+= "', ";
    sql+= std::to_string(this->deviceId);
    sql+= ")";

    return sql;
}

double Measurement::getValue() const {
    return this->value;
}

long Measurement::getDeviceId() const {
    return this->deviceId;
}
std::string Measurement::getTimestamp() const {
    return boost::posix_time::to_simple_string(this->timestamp);
}
std::unique_ptr<std::vector<Measurement>> Measurement::mapToMeasurements(std::unique_ptr<std::vector<std::string>> stringVector) {
    std::unique_ptr<std::vector<Measurement>>measurementSet = std::make_unique<std::vector<Measurement>>();

    for (unsigned i = 0; i < stringVector->size(); i=i+4) {
        measurementSet->push_back(Measurement(stringVector->at(i), stringVector->at(i+1),stringVector->at(i+2),stringVector->at(i+3)));
    }

    return measurementSet;
}

const std::string Measurement::mapEntityToSQLSelect(const boost::python::dict& args) {
    std::string sql = "SELECT * FROM ";
    sql+= tableName;
    sql+=" WHERE timestamp>'";
    sql+= extractKeyFromPythonDict(args, "startTime").c_str();
    sql+= "' AND timestamp<'";
    sql+= extractKeyFromPythonDict(args, "stopTime").c_str();
    sql+= "' AND device_id='";
    sql+= extractKeyFromPythonDict(args, "deviceId").c_str();
    sql+= "';";

    return sql;
}
}