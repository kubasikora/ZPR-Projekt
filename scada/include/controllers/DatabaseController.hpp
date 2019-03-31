#ifndef __DATABASE_CONTROLLER_HPP_
#define __DATABASE_CONTROLLER_HPP_

#include<string>
#include<boost/python.hpp>

namespace zpr {

class DatabaseController {
  public:
    DatabaseController(boost::python::dict& env);
  
    std::string host;
    std::string user;
    std::string password;
    std::string port;
};

}
#endif //__DATABASE_CONTROLLER_HPP_
