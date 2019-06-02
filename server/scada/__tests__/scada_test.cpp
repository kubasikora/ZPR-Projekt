#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE ZPR

#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

