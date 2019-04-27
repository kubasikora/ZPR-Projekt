#ifndef __UTILITIES_HPP_
#define __UTILITIES_HPP_

#include<string>
#include<boost/python.hpp>
#include<exception>
#include<boost/date_time/posix_time/ptime.hpp>
#include<memory>

namespace zpr {

class KeyDoNotExistsException : public std::exception {
    public:
        KeyDoNotExistsException(std::string key) : key(key) {}
        std::string key;
};

std::string extractKeyFromPythonDict(const boost::python::dict& dict, std::string key);
std::string pTimeToTimestamp(const boost::posix_time::ptime &time);
boost::posix_time::ptime timestampToPTime(const std::string timestamp);

}

#endif //__UTILITIES_HPP_