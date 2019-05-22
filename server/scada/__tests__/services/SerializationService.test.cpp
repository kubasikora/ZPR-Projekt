#define BOOST_TEST_DYN_LINK
#ifdef __unix__              
    #include <boost/test/unit_test.hpp>
#elif defined(_WIN32) || defined(WIN32)
    #include <boost/test/included/unit_test.hpp>
#endif


#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
#include<boost/python/extract.hpp>
#include<boost/python/object.hpp>
#include<string>
#include<exception>
#include<memory>
#include<vector>
#include<stdexcept>
#define protected public
#define private   public
#include"services/SerializationService.hpp"
#undef protected
#undef private
#include"mappers/Measurement.hpp"

BOOST_AUTO_TEST_SUITE( SerializationServiceTests )

BOOST_AUTO_TEST_CASE( createsSerializationService )
{
    BOOST_IS_DEFINED( zpr::SerializationServce());
   
}

// BOOST_AUTO_TEST_CASE( mapsToPythonDict )
// {    

// }

BOOST_AUTO_TEST_CASE( resamplesWhenVectorIsTooLong )
{  
    Py_Initialize();
    std::unique_ptr<std::vector<zpr::Measurement>> measurements = std::make_unique<std::vector<zpr::Measurement>>();
    const double size = 200;
    const std::string exampleValueKey = "value";
    const std:: string exampleDeviceIdKey = "deviceId";
    const std:: string exampleDeviceId = "5";
    
    for (int i = 0; i < size; ++i) {
        const std::string exampleValue =  std::to_string(i);
        boost::python::dict data;
        data[exampleValueKey] = exampleValue;
        data[exampleDeviceIdKey] = exampleDeviceId;
        measurements->push_back(zpr::Measurement(data));
    }
    zpr::SerializationService service = zpr::SerializationService();
    measurements = service.resample(std::move(measurements));
    BOOST_CHECK_EQUAL((unsigned int)(service.resample(std::move(measurements)))->size(),100 );

}
BOOST_AUTO_TEST_CASE( notResamplesWhenVectorIsTooShort )
{
Py_Initialize();
    std::unique_ptr<std::vector<zpr::Measurement>> measurements = std::make_unique<std::vector<zpr::Measurement>>();
    const double size = 40;
    const std::string exampleValueKey = "value";
    const std:: string exampleDeviceIdKey = "deviceId";
    const std:: string exampleDeviceId = "5";
    
    for (int i = 0; i < size; ++i) {
        const std::string exampleValue =  std::to_string(i);
        boost::python::dict data;
        data[exampleValueKey] = exampleValue;
        data[exampleDeviceIdKey] = exampleDeviceId;
        measurements->push_back(zpr::Measurement(data));
    }
    zpr::SerializationService service = zpr::SerializationService();
    measurements = service.resample(std::move(measurements));
    BOOST_CHECK_EQUAL((unsigned int)(service.resample(std::move(measurements)))->size(),size );

}

BOOST_AUTO_TEST_SUITE_END()