#include<string>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>
#include"controllers/SerializeDataController.hpp"

namespace zpr {

boost::python::dict SerializeDataController::getSerializedData(boost::python::dict& arguments) {
    this->statusCode = 400;
    boost::python::dict dictionary;
    dictionary["message"] = "Not implemented yet";
    return dictionary;
}

}