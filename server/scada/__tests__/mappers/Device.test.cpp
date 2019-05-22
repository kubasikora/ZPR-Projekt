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

#include"mappers/Device.hpp"

BOOST_AUTO_TEST_SUITE( DeviceTests )

BOOST_AUTO_TEST_CASE( createsMeasurementFromStrings )
{
    
    const std::string exampleDeviceId = "1";
    const std::string exampleSerialCode = "1893274832";
    const std::string exampleModel = "ModelX";
    const std::string exampleProducer = "ProducerX";
    const std::string exampleUnit = "u";
    const std::string exampleMinValue = "0.2";
    const std::string exampleMaxValue = "10";
    BOOST_IS_DEFINED( zpr::Measurement(exampleDeviceId,exampleSerialCode,exampleModel,exampleProducer,exampleUnit,exampleMinValue,exampleMaxValue));
}

BOOST_AUTO_TEST_CASE( createsMeasurementFromDict )
{    
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
    BOOST_IS_DEFINED(zpr::Measurement(data));

}

BOOST_AUTO_TEST_SUITE_END()