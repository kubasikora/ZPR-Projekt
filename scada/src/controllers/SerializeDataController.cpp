#include<string>
#include<boost/python.hpp>

#include"controllers/SerializeDataController.hpp"

namespace zpr {

    std::string SerializeDataController::getSerializedData(boost::python::dict& arguments){
        this->statusCode = 400;
        return std::string("Not implemented yet");
    }

}