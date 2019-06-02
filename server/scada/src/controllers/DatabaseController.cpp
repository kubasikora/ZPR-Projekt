#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>

#include"controllers/DatabaseController.hpp"
#include"utilities/utilities.hpp"

namespace zpr {

DatabaseController::DatabaseController(const boost::python::dict& env) {
    this->host = extractKeyFromPythonDict(env, "host");
    this->user = extractKeyFromPythonDict(env, "user");
    this->password = extractKeyFromPythonDict(env, "password");
    this->port = extractKeyFromPythonDict(env, "port");
}

}