#ifndef __STATE_CONTROLLER_HPP_
#define __STATE_CONTROLLER_HPP_

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include"controllers/RESTServiceController.hpp"

namespace zpr {
/**
 * Kontroler odpowiedzialny za zwracanie bieżących pomiarów z urządzeń.
*/
class StateController : public RESTServiceController {
    public:
        double getValue(const int deviceId) const;
        boost::python::list getState();
};

}

#endif //__STATE_CONTROLLER_HPP_