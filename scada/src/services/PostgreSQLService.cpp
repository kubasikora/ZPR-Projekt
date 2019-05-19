#include<vector>
#include<memory>
#include<pqxx/pqxx>
#include<iostream>

#include"services/DatabaseService.hpp"
#include"services/PostgreSQLService.hpp"

namespace zpr {

PostgreSQLService::PostgreSQLService(const std::string host, const std::string user, const std::string password, const std::string port) :
    host(host),
    user(user),
    password(password),
    port(port) {}


std::unique_ptr<std::vector<std::string>> PostgreSQLService::doWork(const std::string query) {
    try {
        std::unique_ptr<pqxx::work> worker = this->getWorker();
        pqxx::result resultDb = worker->exec(query);
        std::unique_ptr<std::vector<std::string>> resultSet = std::make_unique<std::vector<std::string>>();
      
        const int columns = resultDb.columns();

        for (auto record = resultDb.begin(); record != resultDb.end(); ++record) {
            for (int column = 0; column < columns; ++column) {
                resultSet->push_back(std::string((*record)[column].c_str()));
            }
        }

        worker->commit();
        this->connection->disconnect();
        return resultSet;
    }
    catch(pqxx::foreign_key_violation& ex) {
        throw ForeignKeyViolationException();
    }
}

void PostgreSQLService::createConnection() {
    std::string connectionString;
    connectionString = "user=" + this->user + " host=" + this->host + " password=" + this->password + " port=" + this->port;
    this->connection = std::make_unique<pqxx::connection>(connectionString);
}

std::unique_ptr<pqxx::work> PostgreSQLService::getWorker() {
    this->createConnection();
    return std::make_unique<pqxx::work>(*(this->connection));
}

}