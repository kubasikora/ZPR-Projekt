#define BOOST_TEST_DYN_LINK
#ifdef __unix__
#include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
#include <boost/test/included/unit_test.hpp>
#endif

#include<string>
#include<exception>
#include<memory>
#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/extract.hpp>
#include<boost/python/object.hpp>

#include"mappers/Measurement.hpp"

BOOST_AUTO_TEST_SUITE( MeasurementTests )

BOOST_AUTO_TEST_CASE( createsMeasurementFromStrings ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleValue = "25.5";
    const std::string exampleTimestamp = "2002-Jan-31 23:59:00";
    const std:: string exampleId = "5";
    auto measurement = zpr::Measurement(exampleId, exampleValue, exampleTimestamp, exampleDeviceId);
    BOOST_IS_DEFINED( measurement );
    BOOST_CHECK_EQUAL(measurement.getDeviceId(), std::stoi(exampleDeviceId));
    BOOST_CHECK_EQUAL(measurement.getValue(),std::stod(exampleValue));
    BOOST_CHECK_EQUAL(measurement.getTimestamp(),exampleTimestamp );

}

BOOST_AUTO_TEST_CASE( createsMeasurementFromDict ) {
    Py_Initialize();
    boost::python::dict data;
    const std::string exampleValueKey = "value";
    const std::string exampleValue = "25.5";
    const std:: string exampleDeviceIdKey = "deviceId";
    const std:: string exampleDeviceId = "5";
    data[exampleValueKey] = exampleValue;
    data[exampleDeviceIdKey] = exampleDeviceId;
    auto measurement = zpr::Measurement(data);
    BOOST_IS_DEFINED(measurement);
    BOOST_CHECK_EQUAL(measurement.getDeviceId(), std::stoi(exampleDeviceId));
    BOOST_CHECK_EQUAL(measurement.getValue(),std::stod(exampleValue));
    BOOST_IS_DEFINED(measurement.getTimestamp());

}

BOOST_AUTO_TEST_CASE( MapsEntityToSQLSelect ) {

    boost::python::dict data;
    const std::string exampleStartTimeKey = "startTime";
    const std::string exampleStartTime = "2002-Jan-30 23:59:00";
    const std::string exampleStopTimeKey = "stopTime";
    const std::string exampleStopTime = "2002-Jan-31 23:59:00";
    const std:: string exampleDeviceIdKey = "deviceId";
    const std:: string exampleDeviceId = "5";
    data[exampleStartTimeKey] = exampleStartTime;
    data[exampleStopTimeKey] = exampleStopTime;
    data[exampleDeviceIdKey] = exampleDeviceId;
    const std::string properSelect = "SELECT * FROM measurements WHERE timestamp>'2002-Jan-30 23:59:00' AND timestamp<'2002-Jan-31 23:59:00' AND device_id='5';";
    BOOST_CHECK_EQUAL(zpr::Measurement::mapEntityToSQLSelect(data),properSelect);

}
BOOST_AUTO_TEST_CASE( MapsEntityToSQLInsert ) {
    const std::string exampleDeviceId = "1";
    const std::string exampleValue = "25.5";
    const std::string exampleTimestamp = "2002-Jan-31 23:59:00";
    const std:: string exampleId = "5";
    auto measurement = zpr::Measurement(exampleId, exampleValue, exampleTimestamp, exampleDeviceId);
    const std::string properInsert = "INSERT INTO measurements VALUES (default, 25.500000, TIMESTAMP '2002-Jan-31 23:59:00', 1)";
    BOOST_CHECK_EQUAL(measurement.mapEntityToSQLInsert(), properInsert);
}

BOOST_AUTO_TEST_SUITE_END()