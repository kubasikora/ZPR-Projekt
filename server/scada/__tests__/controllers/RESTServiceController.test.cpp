#define BOOST_TEST_DYN_LINK
#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#define protected public
#define private   public
#include"controllers/RESTServiceController.hpp"
#undef protected
#undef private

BOOST_AUTO_TEST_SUITE( RESTServiceControllerTests )

BOOST_AUTO_TEST_CASE( createsRESTServiceController ){
    BOOST_IS_DEFINED(zpr::RESTServiceController());
}

BOOST_AUTO_TEST_CASE( iniatilizesControllerWithUndefinedStatusCode ){
    zpr::RESTServiceController controller;
    BOOST_CHECK_EQUAL(controller.getStatusCode(), 418);
}

BOOST_AUTO_TEST_SUITE_END()