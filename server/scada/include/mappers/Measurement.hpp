#ifndef __MEASUREMENT_HPP_
#define __MEASUREMENT_HPP_

#include<boost/python.hpp>
#include<boost/date_time.hpp>
#include"mappers/Entity.hpp"

namespace zpr {

class Measurement : public Entity {
    public:
        Measurement();
        Measurement(const std::string id, const std::string value, const std::string timestamp, const std::string deviceId);
        Measurement(const boost::python::dict& request);
        virtual const std::string mapEntityToSQLInsert() const;
        double getValue() const;
        long getDeviceId() const;
        std::string getTimestamp() const;
        static const std::string mapEntityToSQLSelect(const boost::python::dict& args);
        static std::unique_ptr<std::vector<Measurement>> mapToMeasurements(std::unique_ptr<std::vector<std::string>> stringVector);
    private:
        double value;
        long deviceId;
        boost::posix_time::ptime timestamp;
        static const std::string tableName;

};

}

#endif //__MEASUREMENT_HPP_