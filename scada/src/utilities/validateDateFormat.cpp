#include<memory>
#include<string>

namespace zpr {

std::string validateDateFormat(std::string timestamp) {
    if (timestamp.length()> 19){
        timestamp.erase(19,3);
    }
    return timestamp;
}

}