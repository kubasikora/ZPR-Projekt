#ifndef __UTILITIES_HPP_
#define __UTILITIES_HPP_

#include<string>
#include<boost/python.hpp>
#include<exception>
#include<boost/date_time/posix_time/ptime.hpp>
#include<memory>

namespace zpr {
/**
 * Klasa wyjątku braku klucza w słowniku.
 */
class KeyDoNotExistsException : public std::exception {
    public:
        KeyDoNotExistsException(std::string key) : key(key) {}
        std::string key;
};
/**
 * Wydobywanie wartości danego klucza z podanego słownika.
 */
std::string extractKeyFromPythonDict(const boost::python::dict& dict, std::string key);
/**
 * Konwersja reprezentacji czasu z czasu w formacie posix na string
 */
std::string pTimeToTimestamp(const boost::posix_time::ptime &time);
/**
 * Konwersja czasu ze stringa na format posix
 */
boost::posix_time::ptime timestampToPTime(const std::string timestamp);
/**
 * Walidacja formatu czasu- pozbywanie się strefy czasowej
 */
std::string validateDateFormat(std::string timestamp);
}

#endif //__UTILITIES_HPP_