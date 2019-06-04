#ifndef __REST_SERVICE_CONTROLLER_HPP_
#define __REST_SERVICE_CONTROLLER_HPP_

namespace zpr {

const int TEAPOT_CODE = 418;
/**
 * Kontroler zwracający kod odpowiedzi
 */
class RESTServiceController {
    public:
        RESTServiceController() : statusCode(TEAPOT_CODE) {}
        int getStatusCode() {
            return this->statusCode;
        }
    protected:
        int statusCode;
};

}

#endif //__REST_SERVICE_CONTROLLER_HPP_