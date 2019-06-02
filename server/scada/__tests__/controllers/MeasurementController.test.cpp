#define BOOST_TEST_DYN_LINK
#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#define protected public
#define private   public
#include"controllers/MeasurementController.hpp"
#undef protected
#undef private

#include"utilities/utilities.hpp"

BOOST_AUTO_TEST_SUITE( MeasurementControllerTests )

BOOST_AUTO_TEST_CASE( createsMeasurementController ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    BOOST_IS_DEFINED(zpr::MeasurementController(db));
}

BOOST_AUTO_TEST_CASE( returnsErrorInfOnBadMeasurement ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::MeasurementController controller(db);
    boost::python::dict measurement;
    BOOST_CHECK_EQUAL(controller.postNewMeasurement(measurement), "Missing key value");
}

BOOST_AUTO_TEST_CASE( returnsErrorInfOnBadMeasurementValue ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::MeasurementController controller(db);
    boost::python::dict measurement;
    measurement["deviceId"] = "1";
    BOOST_CHECK_EQUAL(controller.postNewMeasurement(measurement), "Missing key value");
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 400);
}


BOOST_AUTO_TEST_CASE( returnsErrorInfoOnBadMeasurementDeviceId ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::MeasurementController controller(db);
    boost::python::dict measurement;
    measurement["value"] = "34.5";
    BOOST_CHECK_EQUAL(controller.postNewMeasurement(measurement), "Missing key deviceId");
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 400);
}

BOOST_AUTO_TEST_CASE( correctlyPostData ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "localhost";
    db["user"] = "zpr";
    db["password"] = "zpr";
    db["port"] = "5432";
    zpr::MeasurementController controller(db);
    boost::python::dict measurement;
    measurement["deviceId"] = "1";
    measurement["value"] = "34.5";
    BOOST_CHECK_EQUAL(controller.postNewMeasurement(measurement), "OK");
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 201);
}

BOOST_AUTO_TEST_CASE( invalidKey ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::MeasurementController controller(db);
    boost::python::dict measurement;
    measurement["deviceId"] = "abasd";
    measurement["value"] = "34.5";
    BOOST_CHECK_EQUAL(controller.postNewMeasurement(measurement), "Invalid key");
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 400);
}

BOOST_AUTO_TEST_CASE( nonexistingDevice ){
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "localhost";
    db["user"] = "zpr";
    db["password"] = "zpr";
    db["port"] = "5432";
    zpr::MeasurementController controller(db);
    boost::python::dict measurement;
    measurement["deviceId"] = "-1";
    measurement["value"] = "34.5";
    BOOST_CHECK_EQUAL(controller.postNewMeasurement(measurement), "Nonexisting device");
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 400);
}


BOOST_AUTO_TEST_SUITE_END()