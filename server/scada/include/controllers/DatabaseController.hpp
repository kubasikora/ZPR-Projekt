#ifndef __DATABASE_CONTROLLER_HPP_
#define __DATABASE_CONTROLLER_HPP_

#include<string>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>
namespace zpr {
/**
* Kontroler bazy danych
*/
class DatabaseController {
    public:
    /**
     * @params env słownik z parametrami niezbędnymi do nawiązania połączenia z bazą danych
     */
        DatabaseController(const boost::python::dict& env);

    protected:
        std::string host;
        std::string user;
        std::string password;
        std::string port;
};

}
#endif //__DATABASE_CONTROLLER_HPP_
