#include<boost/python.hpp>
#include"foo.h"

#include<iostream>


BOOST_PYTHON_MODULE(libscada) {
    boost::python::def("foo", zpr::foo);
    boost::python::def("getData", zpr::getData);
}

/*
int main(){
    std::cout << zpr::getData() << std::endl;
    return 0;
}
*/
