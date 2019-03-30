#include<vector>
#include<memory>
#include<pqxx/pqxx>

#include"services/PostgreSQLService.hpp"

namespace zpr {

PostgreSQLService::PostgreSQLService(std::string host, std::string user, std::string password, std::string port){
    this->host = host;
    this->user = user;
    this->password = password;
    this->port = port;
}

std::shared_ptr<pqxx::connection> PostgreSQLService::createConnection(){
    std::string connectionString; 
    connectionString = "user=" + this->user + " host=" + this->host + " password=" + this->password + " port=" + this->port;
    return std::make_shared<pqxx::connection>(connectionString);
}

std::shared_ptr<pqxx::work> PostgreSQLService::getDatabase() {
    std::shared_ptr<pqxx::connection> conn = createConnection();
    return std::make_shared<pqxx::work>(*conn);
}

}