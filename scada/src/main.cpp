#include<boost/python.hpp>
#include"foo.h"

BOOST_PYTHON_MODULE(libscada) {
    boost::python::def("foo", zpr::foo);
}