#include<string>
#include<boost/python.hpp>

#include"controllers/SerializeDataController.hpp"

namespace zpr {

boost::python::dict SerializeDataController::getSerializedData(boost::python::dict& arguments) {
    this->statusCode = 400;
    boost::python::dict dictionary;
    dictionary["message"] = "Not implemented yet";
    return dictionary;
}

}