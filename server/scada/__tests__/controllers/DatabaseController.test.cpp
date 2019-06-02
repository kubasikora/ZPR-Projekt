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
#include"utilities/utilities.hpp"

#define protected public
#define private   public
#include "controllers/DatabaseController.hpp"
#undef protected
#undef private

BOOST_AUTO_TEST_SUITE( DatabaseControllerTests )

BOOST_AUTO_TEST_CASE( createsDatabaseControllerTests ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    BOOST_IS_DEFINED( zpr::DatabaseController(db) );
}

BOOST_AUTO_TEST_CASE( databaseControllerHasHost ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::DatabaseController dbController(db);
    BOOST_CHECK_EQUAL(dbController.host, "host");
}

BOOST_AUTO_TEST_CASE( databaseControllerHasUser ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::DatabaseController dbController(db);
    BOOST_CHECK_EQUAL(dbController.user, "user");
}

BOOST_AUTO_TEST_CASE( databaseControllerHasPassword ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::DatabaseController dbController(db);
    BOOST_CHECK_EQUAL(dbController.password, "password");
}

BOOST_AUTO_TEST_CASE( databaseControllerHasPort ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    zpr::DatabaseController dbController(db);
    BOOST_CHECK_EQUAL(dbController.port, "port");
}

BOOST_AUTO_TEST_CASE( throwsOnMissingHost ) {
    Py_Initialize();
    boost::python::dict db;
    db["user"] = "user";
    db["password"] = "password";
    db["port"] = "port";
    BOOST_CHECK_THROW( std::make_unique<zpr::DatabaseController>(db), zpr::KeyDoNotExistsException);
}

BOOST_AUTO_TEST_CASE( throwsOnMissingUser ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["password"] = "password";
    db["port"] = "port";
    BOOST_CHECK_THROW( std::make_unique<zpr::DatabaseController>(db), zpr::KeyDoNotExistsException);
}

BOOST_AUTO_TEST_CASE( throwsOnMissingPassword ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["port"] = "port";
    BOOST_CHECK_THROW( std::make_unique<zpr::DatabaseController>(db), zpr::KeyDoNotExistsException);
}

BOOST_AUTO_TEST_CASE( throwsOnMissingPort ) {
    Py_Initialize();
    boost::python::dict db;
    db["host"] = "host";
    db["user"] = "user";
    db["password"] = "password";
    BOOST_CHECK_THROW( std::make_unique<zpr::DatabaseController>(db), zpr::KeyDoNotExistsException);
}

BOOST_AUTO_TEST_SUITE_END()