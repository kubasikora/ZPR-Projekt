#include<string>
#include<exception>
#include<iostream>
#include<string>

#include<pqxx/pqxx>

namespace zpr {
    std::string foo() {
        return "hello from foo";
    }

    std::string getData(){
        pqxx::connection conn(
            "user=zpr host=localhost password=zpr dbname=zpr port=5432"
        );

        pqxx::work statement(conn);
        pqxx::result resultSet = statement.exec("SELECT * FROM measurements WHERE device_id=2 order by timestamp desc ");    
        if(resultSet.empty()) return "undefined";

        return resultSet[0][1].c_str();
    }
}