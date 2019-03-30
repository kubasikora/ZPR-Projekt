#include<vector>
#include<memory>
#include<pqxx/pqxx>
#include<iostream>

#include"services/PostgreSQLService.hpp"

namespace zpr {

PostgreSQLService::PostgreSQLService(std::string host, std::string user, std::string password, std::string port) {
    this->host = host;
    this->user = user;
    this->password = password;
    this->port = port;
}

std::shared_ptr<std::vector<std::string>> PostgreSQLService::doWork(std::string query){
    std::shared_ptr<pqxx::work> worker = this->getWorker();
    pqxx::result resultDb = worker->exec(query);
    auto resultSet = std::make_shared<std::vector<std::string>>();

    const int columns = resultDb.columns();
    for (auto record = resultDb.begin(); record != resultDb.end(); ++record){
        for (int column = 0; column < columns; ++column){
            std::cout << (*record)[column] << std::endl;
        }
    }

    return resultSet;
}

void PostgreSQLService::createConnection() {
    std::string connectionString; 
    connectionString = "user=" + this->user + " host=" + this->host + " password=" + this->password + " port=" + this->port;
    this->connection = std::make_shared<pqxx::connection>(connectionString);
}

std::shared_ptr<pqxx::work> PostgreSQLService::getWorker() {
    this->createConnection();
    return std::make_shared<pqxx::work>(*(this->connection));
}

}