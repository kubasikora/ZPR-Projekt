#ifndef __STATE_CONTROLLER_HPP_
#define __STATE_CONTROLLER_HPP_

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include"controllers/RESTServiceController.hpp"

namespace zpr {

class StateController : public RESTServiceController {
    public:
        double getValue(int deviceId);
        boost::python::list getState();
};

}

#endif //__STATE_CONTROLLER_HPP_