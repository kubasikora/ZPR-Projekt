#define BOOST_TEST_DYN_LINK

#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#include<string>
#include<exception>

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/extract.hpp>
#include<boost/python/object.hpp>

#include"utilities/utilities.hpp"

BOOST_AUTO_TEST_SUITE( extractKeyFromPythonDictTests )

BOOST_AUTO_TEST_CASE( retrievesValue ) {
    Py_Initialize();
    boost::python::dict data;
    const std::string exampleKey = "exampleKey";
    const std::string exampleValue = "exampleValue";
    data[exampleKey] = exampleValue;
    BOOST_CHECK_EQUAL( zpr::extractKeyFromPythonDict(data, exampleKey), exampleValue);
}

BOOST_AUTO_TEST_CASE( doesntThrowOnCorrectOperation ) {
    boost::python::dict data;
    const std::string exampleKey = "exampleKey";
    const std::string exampleValue = "exampleValue";
    data[exampleKey] = exampleValue;
    BOOST_REQUIRE_NO_THROW(zpr::extractKeyFromPythonDict(data,exampleKey));
}

BOOST_AUTO_TEST_CASE( throwsOnNonExistingKey ) {
    boost::python::dict data;
    const std::string exampleKey = "exampleKey";
    BOOST_CHECK_THROW(zpr::extractKeyFromPythonDict(data,exampleKey), zpr::KeyDoNotExistsException);
}

BOOST_AUTO_TEST_SUITE_END()