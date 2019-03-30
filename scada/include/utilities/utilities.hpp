#ifndef __UTILITIES_HPP_
#define __UTILITIES_HPP_

#include<string>
#include<boost/python.hpp>

namespace zpr {

std::string extractKeyFromPythonDict(boost::python::dict& dict, std::string key);

}

#endif //__UTILITIES_HPP_