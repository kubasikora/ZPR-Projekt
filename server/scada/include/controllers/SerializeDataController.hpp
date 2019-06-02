#ifndef __SERIALIZE_DATA_CONTROLLER_HPP_
#define __SERIALIZE_DATA_CONTROLLER_HPP_

#include<string>
#include"controllers/DatabaseController.hpp"
#include"controllers/RESTServiceController.hpp"
#include"services/SerializationService.hpp"

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>

namespace zpr {

class SerializeDataController : public DatabaseController, public RESTServiceController {
    public:
        SerializeDataController(const boost::python::dict& env) : DatabaseController(env) {}
        boost::python::dict getSerializedData(const boost::python::dict& arguments);
};

}

#endif //__SERIALIZE_DATA_CONTROLLER_HPP_