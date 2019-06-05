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
        /**
         * Pobranie wartości odczytu z pojedynczego urządzenia
         * @params deviceId - id urządzenia
         */
        double getValue(const int deviceId) const;
        /**
         * Metoda zawraca listę z bieżącymi odczytami z wszystkich urządzeń, które zostaną wysłane użytkownikowi
         */
        boost::python::list getState();
};

}

#endif //__STATE_CONTROLLER_HPP_