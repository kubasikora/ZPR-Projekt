#include<iostream>
#include<stdlib.h>
#include<math.h>

#include"xd.h"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    std::cout << "Square root of " << inputValue << " is " << outputValue << std::endl;
    test();
    return 0;
}