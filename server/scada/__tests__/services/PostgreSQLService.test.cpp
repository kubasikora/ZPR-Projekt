#define BOOST_TEST_DYN_LINK
#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#define protected public
#define private   public
#include"services/PostgreSQLService.hpp"
#undef protected
#undef private

BOOST_AUTO_TEST_SUITE( PostgreSQLServiceTests )

BOOST_AUTO_TEST_CASE( createsPostgreSQLService ) {
    BOOST_IS_DEFINED( zpr::PostgreSQLService("host", "user", "pass", "port") );
}

BOOST_AUTO_TEST_CASE( createsConnection ) {
    zpr::PostgreSQLService sqlService("localhost", "zpr", "zpr", "5432");
    sqlService.createConnection();
    BOOST_CHECK(sqlService.connection);
}

BOOST_AUTO_TEST_CASE( createsWorker ) {
    zpr::PostgreSQLService sqlService("localhost", "zpr", "zpr", "5432");
    auto worker = sqlService.getWorker();
    BOOST_CHECK(worker);
}

BOOST_AUTO_TEST_CASE( throwsOnWrongConnectionInfo ) {
    zpr::PostgreSQLService sqlService("localhost", "none", "none", "5432");
    BOOST_CHECK_THROW(sqlService.doWork("SELECT * FROM test"), std::exception);
}

BOOST_AUTO_TEST_CASE( successfulQuery ) {
    zpr::PostgreSQLService sqlService("localhost", "zpr", "zpr", "5432");
    auto result = sqlService.doWork("SELECT * FROM test");
    BOOST_CHECK_NE(result->size(), 0);
}

BOOST_AUTO_TEST_CASE( throwsOnBadSQL ) {
    zpr::PostgreSQLService sqlService("localhost", "zpr", "zpr", "5432");
    BOOST_CHECK_THROW(sqlService.doWork("SELECT bad_column FROM test"), std::exception);
}


BOOST_AUTO_TEST_SUITE_END()