#ifndef __SERIALIZATION_SERVICE_HPP_
#define __SERIALIZATION_SERVICE_HPP_

#include<vector>
#include<memory>
#include<string>
#include<mappers/Measurement.hpp>

#define BOOST_PYTHON_STATIC_LIB
#include<boost/python.hpp>
#include<boost/python/dict.hpp>
namespace zpr {

class SerializationService {
    public:
        //std::unique_ptr<std::vector<Measurement>>mapToMeasurements(std::unique_ptr<std::vector<std::string>> vector);
        boost::python::dict mapToPythonDict(std::unique_ptr<std::vector<Measurement>> measurements);
    private:
        static const int maxSamples;
        std::unique_ptr<std::vector<Measurement>> resample(std::unique_ptr<std::vector<Measurement>> measurement);
};     

}

#endif //__SERIALIZATION_SERVICE_HPP_
