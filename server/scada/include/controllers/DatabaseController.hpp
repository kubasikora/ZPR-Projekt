#ifndef __DATABASE_CONTROLLER_HPP_
#define __DATABASE_CONTROLLER_HPP_

#include<string>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>
namespace zpr {

class DatabaseController {
    public:
        DatabaseController(const boost::python::dict& env);

    protected:
        std::string host;
        std::string user;
        std::string password;
        std::string port;
};

}
#endif //__DATABASE_CONTROLLER_HPP_
