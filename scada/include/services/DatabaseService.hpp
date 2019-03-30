#ifndef __DATABASE_SERVICE_HPP_
#define __DATABASE_SERVICE_HPP_

#include<vector>
#include<memory>

namespace zpr {

class DatabaseService {
  public:
    virtual std::shared_ptr<std::vector<std::string>> doWork(std::string query) = 0;
};

}

#endif //__DATABASE_SERVICE_HPP_