#define BOOST_TEST_DYN_LINK
#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/extract.hpp>
#include<boost/python/object.hpp>

#define protected public
#define private   public
#include"services/StateService.hpp"
#undef protected
#undef private

BOOST_AUTO_TEST_SUITE( SerializationServiceTests )

BOOST_AUTO_TEST_CASE( createsStateService ) {
    BOOST_IS_DEFINED( zpr::StateService() );
}

BOOST_AUTO_TEST_CASE( updatesStateCorrectly ) {
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);

    BOOST_CHECK_CLOSE(34.5, state->getValue(1), 0.0001);
}

BOOST_AUTO_TEST_CASE( correctylHoldsMoreThanOneValue ) {
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    state->updateState(2, 45.4);

    BOOST_CHECK_CLOSE(34.5, state->getValue(1), 0.0001);
    BOOST_CHECK_CLOSE(45.4, state->getValue(2), 0.0001);
}

BOOST_AUTO_TEST_CASE( overwritesStateCorrectly ) {
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    state->updateState(1, 34.9);

    BOOST_CHECK_CLOSE(34.9, state->getValue(1), 0.0001);
}

BOOST_AUTO_TEST_CASE( createsPythonListBasedOnState ) {
    Py_Initialize();
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    state->updateState(2, 43.5);
    state->updateState(3, 23.6);
    state->updateState(4, 30.7);
    boost::python::list listState = state->mapToPythonList();

    BOOST_CHECK_EQUAL(boost::python::len(listState), 4);
}

BOOST_AUTO_TEST_CASE( correctlyTransformsDeviceId ) {
    Py_Initialize();
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    boost::python::list listState = state->mapToPythonList();
    boost::python::dict element = boost::python::extract<boost::python::dict>(listState[0]);

    BOOST_CHECK_EQUAL(boost::python::extract<int>(element["deviceId"]), 1);
}

BOOST_AUTO_TEST_CASE( correctlyTransformsValue ) {
    Py_Initialize();
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 34.5);
    boost::python::list listState = state->mapToPythonList();
    boost::python::dict element = boost::python::extract<boost::python::dict>(listState[0]);

    BOOST_CHECK_EQUAL(boost::python::extract<double>(element["value"]), 34.5);
}

BOOST_AUTO_TEST_CASE( getValueTest ){
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 31.5);
    BOOST_CHECK_EQUAL(state->getValue(1), 31.5);
}

BOOST_AUTO_TEST_CASE( returnsZeroWhenAskedForNonexistentDevice ){
    zpr::StateService* state = zpr::StateService::getInstance();
    state->updateState(1, 31.5);
    BOOST_CHECK_EQUAL(state->getValue(-1), 0.0);    
}

BOOST_AUTO_TEST_SUITE_END()