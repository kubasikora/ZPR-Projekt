#ifndef __APP_STATE_HPP_
#define __APP_STATE_HPP_

#include<boost/python.hpp>
#include<memory>
#include<map>
#include<mutex>

namespace zpr
{

class StateService {
    public:
        static StateService* getInstance();
        void updateState(const int deviceId, const double measurementValue);
        double getValue(const int deviceId);
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