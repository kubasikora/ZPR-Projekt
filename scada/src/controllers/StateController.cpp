#include<memory>
#include<map>

#include"controllers/StateController.hpp"
#include"services/StateService.hpp"

namespace zpr {
    
double StateController::getValue(int deviceId){
    StateService* state = StateService::getInstance();
    return state->getValue(deviceId);
}

}