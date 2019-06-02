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

BOOST_AUTO_TEST_SUITE( timestamToPTimeTopTests )

BOOST_AUTO_TEST_CASE( convertsToPTime ) {
    std::string timestamp = "2002-Jan-31 23:59:59";
    boost::posix_time::ptime expectedTime(boost::posix_time::time_from_string(timestamp));
    BOOST_CHECK_EQUAL(zpr::timestampToPTime(timestamp), expectedTime);
}

BOOST_AUTO_TEST_SUITE_END()