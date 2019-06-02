#define BOOST_TEST_DYN_LINK
#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#define protected public
#define private   public
#include"controllers/StateController.hpp"
#undef protected
#undef private

#include"services/StateService.hpp"

BOOST_AUTO_TEST_SUITE( StateControllerTests )

BOOST_AUTO_TEST_CASE( createsStateController ){
    BOOST_IS_DEFINED(zpr::StateController());
}


BOOST_AUTO_TEST_CASE( returnsPythonListOfGivenSize ){
    Py_Initialize();
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    state->updateState(2, 44.5);
    state->updateState(3, 54.5);
    state->updateState(4, 64.5);

    zpr::StateController controller;
    boost::python::list result = controller.getState();
    BOOST_CHECK_EQUAL(boost::python::len(result), 4);
}

BOOST_AUTO_TEST_CASE( correctStatusCodeAfterGetState ){
    Py_Initialize();
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    state->updateState(2, 44.5);
    state->updateState(3, 54.5);
    state->updateState(4, 64.5);

    zpr::StateController controller;
    controller.getState();
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 200);
}

BOOST_AUTO_TEST_CASE( getValueTest ){
    Py_Initialize();
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 28.5);
    zpr::StateController controller;
    BOOST_CHECK_EQUAL(controller.getValue(1), 28.5);
}

BOOST_AUTO_TEST_SUITE_END()