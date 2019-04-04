#include"mappers/Measurement.hpp"
#include<boost/python.hpp>
#include<boost/date_time.hpp>
#include"utilities/utilities.hpp"
#include<string>
#include<sstream>

namespace zpr {

const std::string Measurement::tableName = "measurements";

Measurement::Measurement() : Entity(0) {

}

Measurement::Measurement(const std::string id, 
            const std::string value, 
            const std::string timestamp, 
            const std::string deviceId) : Entity(std::stoi(id)) {
    this->value = std::stod(value);
    this->timestamp = timestampToPTime(timestamp);
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

}