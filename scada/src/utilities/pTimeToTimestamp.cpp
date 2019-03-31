#include<memory>
#include<boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include<string>

namespace zpr {

std::string pTimeToTimestamp(const boost::posix_time::ptime &time){
    std::stringstream ss;
    ss << time;
    return ss.str();
}

}