#ifndef __REST_SERVICE_CONTROLLER_HPP_
#define __REST_SERVICE_CONTROLLER_HPP_

namespace zpr {

class RESTServiceController {
    public:
        RESTServiceController() : statusCode(418) {}
        int getStatusCode() {
            return this->statusCode;
        }
    protected:
        int statusCode;
};

}

#endif //__REST_SERVICE_CONTROLLER_HPP_