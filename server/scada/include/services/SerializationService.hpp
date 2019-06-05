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
/**
 * Serwis odpowiedzialny za serializację danych
 */
class SerializationService {
    public:
        //std::unique_ptr<std::vector<Measurement>>mapToMeasurements(std::unique_ptr<std::vector<std::string>> vector);
        /**
         * @params measurements- wektor danych  pobranych danych, który zostanie zmapowany na słownik, który zostanie wysłany użytkownikowi
         */
        boost::python::dict mapToPythonDict(std::unique_ptr<std::vector<Measurement>> measurements);
    private:
        static const int maxSamples;
        /**
         * Downsampling danych, gdy jest ich nadmierna ilość
         */
        std::unique_ptr<std::vector<Measurement>> resample(std::unique_ptr<std::vector<Measurement>> measurement);
};

}

#endif //__SERIALIZATION_SERVICE_HPP_
