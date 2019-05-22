#ifndef __POSTGRESQL_SERVICE_HPP_
#define __POSTGRESQL_SERVICE_HPP_

#include<vector>
#include<memory>
#include<pqxx/pqxx>

#include"services/DatabaseService.hpp"

namespace zpr {

class PostgreSQLService : public DatabaseService {
    public:
        PostgreSQLService(const std::string host, const std::string user, const std::string password, const std::string port);
        virtual std::unique_ptr<std::vector<std::string>> doWork(const std::string query);

    private:
        const std::string host;
        const std::string user;
        const std::string password;
        const std::string port;

        std::unique_ptr<pqxx::connection> connection;

        void createConnection();
        std::unique_ptr<pqxx::work> getWorker();
};

}

#endif //__POSTGRESQL_SERVICE_HPP_
