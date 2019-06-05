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

#define protected public
#define private   public
#include"mappers/Device.hpp"
#undef protected
#undef private


BOOST_AUTO_TEST_SUITE( DeviceTests )

BOOST_AUTO_TEST_CASE( createsMeasurementFromStrings ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    BOOST_IS_DEFINED( zpr::Device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue));
}

BOOST_AUTO_TEST_CASE( testDeviceId ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.id, 1L);

}


BOOST_AUTO_TEST_CASE( testIdOnNoParams ) {
    zpr::Device device;
    BOOST_CHECK_EQUAL(device.id, 0);

}

BOOST_AUTO_TEST_CASE( testDeviceSerialCode ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.serialCode, exampleSerialCode);
}

BOOST_AUTO_TEST_CASE( testDeviceModel ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.model, exampleModel);
}

BOOST_AUTO_TEST_CASE( testDeviceProducer ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.producer, exampleProducer);
}

BOOST_AUTO_TEST_CASE( testDeviceUnit) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.unit, exampleUnit);
}

BOOST_AUTO_TEST_CASE( testDeviceMin ) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.minValue, 0.2);
}

BOOST_AUTO_TEST_CASE( testDeviceMax) {

    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    zpr::Device device(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue);
    BOOST_CHECK_EQUAL(device.maxValue, 10.0);
}




BOOST_AUTO_TEST_CASE( createsMeasurementFromDict ) {
    Py_Initialize();
    boost::python::dict data;
    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";

    const std::string exampleDeviceIdKey = "deviceId";
    const std::string exampleSerialCodeKey = "serialCode";
    const std::string exampleModelKey = "model";
    const std::string exampleProducerKey = "producer";
    const std::string exampleUnitKey = "unit";
    const std::string exampleMinValueKey = "minValue";
    const std::string exampleMaxValueKey = "maxValue";
    data[exampleSerialCodeKey] = exampleSerialCode;
    data[exampleDeviceIdKey] = exampleDeviceId;
    data[exampleModelKey] = exampleModel;
    data[exampleUnitKey] =  exampleUnit;
    data[exampleProducerKey] = exampleProducer;
    data[exampleMinValueKey] = exampleMinValue;
    data[exampleMaxValueKey] = exampleMaxValue;
    BOOST_IS_DEFINED(zpr::Device(data));

}

BOOST_AUTO_TEST_CASE( doesntCreateMeasurementFromDictnoMinValue ) {
    Py_Initialize();
    boost::python::dict data;
    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";

    const std::string exampleDeviceIdKey = "deviceId";
    const std::string exampleSerialCodeKey = "serialCode";
    const std::string exampleModelKey = "model";
    const std::string exampleProducerKey = "producer";
    const std::string exampleUnitKey = "unit";
    const std::string exampleMinValueKey = "minValue";
   
    data[exampleSerialCodeKey] = exampleSerialCode;
    data[exampleDeviceIdKey] = exampleDeviceId;
    data[exampleModelKey] = exampleModel;
    data[exampleUnitKey] =  exampleUnit;
    data[exampleProducerKey] = exampleProducer;
    data[exampleMinValueKey] = exampleMinValue;
    BOOST_REQUIRE_THROW(zpr::Device device(data), std::exception);

}
BOOST_AUTO_TEST_CASE( doesntCreateMeasurementFromDictnoMaxValue ) {
    Py_Initialize();
    boost::python::dict data;
    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";

    const std::string exampleDeviceIdKey = "deviceId";
    const std::string exampleSerialCodeKey = "serialCode";
    const std::string exampleModelKey = "model";
    const std::string exampleProducerKey = "producer";
    const std::string exampleUnitKey = "unit";
    const std::string exampleMinValueKey = "maxValue";
   
    data[exampleSerialCodeKey] = exampleSerialCode;
    data[exampleDeviceIdKey] = exampleDeviceId;
    data[exampleModelKey] = exampleModel;
    data[exampleUnitKey] =  exampleUnit;
    data[exampleProducerKey] = exampleProducer;
    data[exampleMinValueKey] = exampleMinValue;
    BOOST_REQUIRE_THROW(zpr::Device device(data), std::exception);

}

BOOST_AUTO_TEST_SUITE_END()