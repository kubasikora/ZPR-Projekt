#ifndef __UTILITIES_HPP_
#define __UTILITIES_HPP_

#include<string>
#include<boost/python.hpp>
#include<boost/date_time/posix_time/ptime.hpp>
#include<memory>

namespace zpr {

std::string extractKeyFromPythonDict(const boost::python::dict& dict, std::string key);
std::string pTimeToTimestamp(const boost::posix_time::ptime &time);
std::shared_ptr<boost::posix_time::ptime> timestampToPTime(const std::string timestamp);

}

#endif //__UTILITIES_HPP_