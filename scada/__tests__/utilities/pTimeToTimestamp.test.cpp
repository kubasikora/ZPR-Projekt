#define BOOST_TEST_DYN_LINK

#ifdef __unix__              
    #include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
    #include <boost/test/included/unit_test.hpp>
#endif

#include<string>
#include<exception>

#include<boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_io.hpp>

#include"utilities/utilities.hpp"

BOOST_AUTO_TEST_SUITE( pTimeToTimestampTests )

BOOST_AUTO_TEST_CASE( convertsToTimestamp )
{
    std::string isoTime = "20020131T235959";
    std::string expectedTimestamp = "2002-Jan-31 23:59:59";
    boost::posix_time::ptime exampleTime(boost::posix_time::from_iso_string(isoTime));
    BOOST_CHECK_EQUAL(zpr::pTimeToTimestamp(exampleTime), expectedTimestamp);
}

BOOST_AUTO_TEST_SUITE_END()