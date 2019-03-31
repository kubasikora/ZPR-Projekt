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

Measurement::Measurement(const boost::python::dict& request) : Entity(0) {
    this->value = atof(extractKeyFromPythonDict(request, "value").c_str());
    this->deviceId = atoi(extractKeyFromPythonDict(request, "deviceId").c_str());
    this->timestamp = boost::posix_time::second_clock::local_time();
}

std::string Measurement::mapEntityToSQLInsert() {
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

}