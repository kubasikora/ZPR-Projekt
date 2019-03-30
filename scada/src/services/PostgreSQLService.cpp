#include<vector>
#include<memory>
#include<pqxx/pqxx>

#include"services/PostgreSQLService.hpp"

namespace zpr {

PostgreSQLService::PostgreSQLService(std::string host, std::string user, std::string password, std::string port) {
    this->host = host;
    this->user = user;
    this->password = password;
    this->port = port;
}

std::shared_ptr<std::vector<std::string>> doWork(std::string query){
    auto result = std::make_shared<std::vector<std::string>>();
    result->push_back(query);
    return result;
}

void PostgreSQLService::createConnection() {
    std::string connectionString; 
    connectionString = "user=" + this->user + " host=" + this->host + " password=" + this->password + " port=" + this->port;
    this->connection = std::make_shared<pqxx::connection>(connectionString);
}

std::shared_ptr<pqxx::work> PostgreSQLService::getWorker() {
    return std::make_shared<pqxx::work>(*(this->connection));
}

}