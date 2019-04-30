#ifndef __SERIALIZE_DATA_CONTROLLER_HPP_
#define __SERIALIZE_DATA_CONTROLLER_HPP_

#include<string>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>

#include"controllers/DatabaseController.hpp"
#include"controllers/RESTServiceController.hpp"

namespace zpr {

class SerializeDataController : public DatabaseController, public RESTServiceController {
    public:
        SerializeDataController(boost::python::dict& env) : DatabaseController(env) {}
        boost::python::dict getSerializedData(boost::python::dict& arguments);
};

}

#endif //__SERIALIZE_DATA_CONTROLLER_HPP_