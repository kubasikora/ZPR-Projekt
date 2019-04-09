#ifndef __STATE_CONTROLLER_HPP_
#define __STATE_CONTROLLER_HPP_

#include<boost/python.hpp>
#include"controllers/RESTServiceController.hpp"

namespace zpr {
 
class StateController : public RESTServiceController {
  public:
    double getValue(int deviceId);
    boost::python::dict getState();
};

} 

#endif //__STATE_CONTROLLER_HPP_