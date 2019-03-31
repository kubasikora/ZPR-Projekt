#ifndef __POSTGRESQL_SERVICE_HPP_
#define __POSTGRESQL_SERVICE_HPP_

#include<vector>
#include<memory>
#include<pqxx/pqxx>

#include"services/DatabaseService.hpp"

namespace zpr {

class PostgreSQLService : public DatabaseService {
  public:
    PostgreSQLService(std::string host, std::string user, std::string password, std::string port);
    virtual std::shared_ptr<std::vector<std::string>> doWork(const std::string query);

  private:
    std::string host;
    std::string user;
    std::string password;
    std::string port;

    std::shared_ptr<pqxx::connection> connection;

    void createConnection();
    std::shared_ptr<pqxx::work> getWorker();
};

}

#endif //__POSTGRESQL_SERVICE_HPP_
