#include<boost/python.hpp>
#include"controllers/DatabaseController.hpp"
#include"utilities/utilities.hpp"

namespace zpr {

DatabaseController::DatabaseController(boost::python::dict& env) {
    this->host = extractKeyFromPythonDict(env, "host");
    this->user = extractKeyFromPythonDict(env, "user");
    this->password = extractKeyFromPythonDict(env, "password");
    this->port = extractKeyFromPythonDict(env, "port");
}

}