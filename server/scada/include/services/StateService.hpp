#ifndef __APP_STATE_HPP_
#define __APP_STATE_HPP_

#include<boost/python.hpp>
#include<memory>
#include<map>
#include<mutex>

namespace zpr {

class StateService {
    /**
     * Serwis zajmujący się bieżącymi pomiarami - singleton.
     */
    public:
        static StateService* getInstance();
        /**
         * Aktualizacja bieżącego stanu konkretnego urządzenia
         * @params deviceId - identyfikator urządzenia, którego stan zostanie zaktualizowany
         */
        void updateState(const int deviceId, const double measurementValue);
        /**
         * Pobranie aktualnej wartości pomiaru dla konkretnego urządzenia
         */
        double getValue(const int deviceId);
        /**
         * Mapowanie najnowszych wyników pomiarów wszystkich urządzeń na listę, która zostanie przesłana użytkownikowi.
         */
        boost::python::list mapToPythonList();
    private:
        StateService() {}
        StateService(const StateService&) = delete;
        StateService& operator=(const StateService&) = delete;
        static StateService* instance;
        std::map<int, double> state;
};

struct Lock {
    Lock(std::mutex& m) : m(m) {
        m.lock();
    }
    ~Lock() {
        m.unlock();
    }
    std::mutex& m;
};

}


#endif //__APP_STATE_HPP_