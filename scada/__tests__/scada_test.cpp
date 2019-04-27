/**
   scada library tests
   defines 'main' for cpp unit test
**/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "controllers/StateController.hpp"

using namespace boost;
using boost::unit_test::test_suite;

BOOST_AUTO_TEST_SUITE( scada_test )

BOOST_AUTO_TEST_CASE( creates_controller )
{
    auto controller = zpr::StateController();
	BOOST_CHECK_EQUAL( 1, 1 );
}

BOOST_AUTO_TEST_SUITE_END()
