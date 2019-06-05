#ifndef __POSTGRESQL_SERVICE_HPP_
#define __POSTGRESQL_SERVICE_HPP_

#include<vector>
#include<memory>
#include<pqxx/pqxx>

#include"services/DatabaseService.hpp"

namespace zpr {
/**
 * Zapewnienie interfejsu do współpracy z konkretną bazą danych
 */
class PostgreSQLService : public DatabaseService {
    public:
        /**
         * Konstruktor przyjmujący parametry niezbędne do nawiązania połączenia i wykonywania operacji na bazie.
         */
        PostgreSQLService(const std::string host, const std::string user, const std::string password, const std::string port);
        /**
         * Wykonanie danego polecenia i zwracanie tablicy z wartościami pobranymi z bazy danych.
         * @params query - polecenie
         */
        virtual std::unique_ptr<std::vector<std::string>> doWork(const std::string query);

    private:
        const std::string host;
        const std::string user;
        const std::string password;
        const std::string port;

        std::unique_ptr<pqxx::connection> connection;
        /**
         * Nawiązanie połączenia z bazą danych.
         */
        void createConnection();
        std::unique_ptr<pqxx::work> getWorker();
};

}

#endif //__POSTGRESQL_SERVICE_HPP_
