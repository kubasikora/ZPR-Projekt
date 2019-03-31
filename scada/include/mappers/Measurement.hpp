#ifndef __MEASUREMENT_HPP_
#define __MEASUREMENT_HPP

#include<boost/date_time.hpp>
#include"mappers/Entity.hpp"

namespace zpr { 

class Measurement : public Entity {
  public:
    Measurement();
    Measurement(std::string id, std::string value, std::string timestamp, std::string deviceId);
    Measurement(const boost::python::dict& request);
    virtual std::string mapEntityToSQLInsert();
  private:
    static const std::string tableName;
    double value;
    long deviceId;
    boost::posix_time::ptime timestamp;
};

}

#endif //__MEASUREMENT_HPP_