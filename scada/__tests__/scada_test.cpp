/**
   scada library tests
   defines 'main' for cpp unit test
**/


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE MyTest

#ifdef __unix__              
    #include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
    #include <boost/test/included/unit_test.hpp>
#endif

#include"controllers/StateController.hpp"
#include"controllers/SerializeDataController.hpp"
#include"controllers/DatabaseController.hpp"
#include<string>
#include<iostream>
#include<memory>

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/extract.hpp>
#include<boost/python/object.hpp>
using namespace boost;
using boost::unit_test::test_suite;

BOOST_AUTO_TEST_SUITE( scada_test )

BOOST_AUTO_TEST_CASE( creates_state_controller )
{
    Py_Initialize();
    boost::python::dict data;
    BOOST_CHECK_EQUAL( 1, 1 );
}

BOOST_AUTO_TEST_CASE( different_test )
{    
    BOOST_CHECK_EQUAL( 2, 2 );
}

BOOST_AUTO_TEST_SUITE_END()
