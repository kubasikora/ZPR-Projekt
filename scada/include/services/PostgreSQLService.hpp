#ifndef __POSTGRESQL_SERVICE_H_
#define __POSTGRESQL_SERVICE_H_

#include<set>
#include<pqxx/pqxx>
#include<memory>

namespace zpr {

class PostgreSQLService {
  public:
    PostgreSQLService(std::string host, std::string user, std::string password, std::string port);
    std::shared_ptr<pqxx::work> getDatabase();

  private:
    std::string host;
    std::string user;
    std::string password;
    std::string port;
    std::shared_ptr<pqxx::connection> createConnection();
};

}

#endif //__POSTGRESQL_SERVICE_H_
