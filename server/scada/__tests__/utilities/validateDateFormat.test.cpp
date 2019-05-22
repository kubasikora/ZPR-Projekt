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

BOOST_AUTO_TEST_SUITE( validateDateFormat )

BOOST_AUTO_TEST_CASE( keepsProperTimestampsUnchanged )
{
    std::string timestamp = "2002-01-31 23:59:59";
    std::string validatedTimestamp = zpr::validateDateFormat(timestamp);
    BOOST_CHECK_EQUAL(timestamp, validatedTimestamp);
}

BOOST_AUTO_TEST_CASE( shortensTooLongTimestamps )
{
    std::string timestamp = "2002-01-31 23:59:59:00";
    std::string validatedTimestamp = zpr::validateDateFormat(timestamp);
    std::string expectedTimestamp = "2002-01-31 23:59:59";
    BOOST_CHECK_EQUAL(expectedTimestamp, validatedTimestamp);
}

BOOST_AUTO_TEST_CASE( removesTimezone )
{
    std::string timestamp = "2002-01-31 23:59:59+02";
    std::string validatedTimestamp = zpr::validateDateFormat(timestamp);
    std::string expectedTimestamp = "2002-01-31 23:59:59";
    BOOST_CHECK_EQUAL(expectedTimestamp, validatedTimestamp);
}

BOOST_AUTO_TEST_SUITE_END()