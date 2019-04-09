#ifndef __APP_STATE_HPP_
#define __APP_STATE_HPP_

#include<memory>
#include<map>
#include<mutex>

namespace zpr
{
  class StateService {
  public:
    static StateService* getInstance();
    void updateState(int deviceId, double measurementValue);
    double getValue(int deviceId);
  private:
    StateService() {}
    StateService(const StateService&) = delete;
    StateService& operator=(const StateService&) = delete;
    static StateService* instance;
    std::map<int, double> state;
};

struct Lock {
    Lock(std::mutex& m) : m(m) {m.lock();}
    ~Lock() {m.unlock();}
    std::mutex& m;
};

} 


#endif //__APP_STATE_HPP_