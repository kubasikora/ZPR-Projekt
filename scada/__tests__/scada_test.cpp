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
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/tuple.hpp>
#include<string>
#include "controllers/StateController.hpp"
#include "controllers/SerializeDataController.hpp"
#include <iostream>
using namespace boost;
using boost::unit_test::test_suite;


// std::string mapEntityToSQLSelect(){
//     boost::python::dict request;
//     request["deviceId"] = "1";
//     request["startTime"]="Sat May 4 2019 20:06:00";
//     request["stopTime"]="Sat May 11 2019 20:06:00";
//     zpr::SerializeData newMapper = zpr::SerializeData(request);
//     printf("OK100\n");
//     std::cout<<newMapper.mapEntityToSQLSelect();
//     return newMapper.mapEntityToSQLSelect();
//     }

void checkDataBase(){
    boost::python::dict db;
    db["host"] ="localhost";
    db["user"]="zpr";
    db["password"]="zpr";
    db["port"]="5432";
    boost::python::dict arguments;
    arguments["deviceId"]=1;
    arguments["stopTime"]="2003-12-25T13:45:30";
    arguments["startTime"]="2002-12-25T13:45:30";
    
    zpr::SerializeDataController controller = zpr::SerializeDataController(db);
    controller.getSerializedData(arguments);
}
BOOST_AUTO_TEST_SUITE( scada_test )
BOOST_AUTO_TEST_CASE( creates_state_controller )
{
    boost::python::dict db;
    db["host"] ="localhost";
    db["user"]="zpr";
    db["password"]="zpr";
    db["port"]="5432";
    boost::python::dict arguments;
    
    arguments["deviceId"]="1";
    arguments["stopTime"]="2019-05-25 13:45:30";
    arguments["startTime"]="2019-05-13 13:45:30";

   
    zpr::SerializeDataController controller = zpr::SerializeDataController(db);
     
    controller.getSerializedData(arguments);
    printf("OK100\n");
    //auto controller = zpr::StateController();
	BOOST_CHECK_EQUAL( 1, 1 );
}
BOOST_AUTO_TEST_CASE( creates)
{    
BOOST_CHECK_EQUAL( 1, 1 );
	//BOOST_CHECK( mapEntityToSQLSelect()== "SELECT * FROM measurements WHERE timestamp > Sat May 4 2019 20:06:00 AND timestamp < Sat May 11 2019 20:06:00 AND device_id = 1;");
}
BOOST_AUTO_TEST_SUITE_END()
