#include<memory>
#include<boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include<string>

namespace zpr {

boost::posix_time::ptime timestampToPTime(const std::string timestamp){
    boost::posix_time::ptime timeObject = boost::posix_time::ptime();
    timeObject = boost::posix_time::time_from_string(timestamp);
    return timeObject;
}

}