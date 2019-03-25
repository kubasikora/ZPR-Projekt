#include<string>
#include<exception>
#include<iostream>
#include<string>

#include<pqxx/pqxx>
//#include<boost/shared_ptr.hpp>



namespace zpr {
    std::string foo() {
        return "hello from foo";
    }

    std::string getData(){
        pqxx::connection conn(
            "user=zpr host=localhost password=zpr dbname=zpr port=5432"
        );

        //std::cout << "Connected to " << conn.dbname() << std::endl;

        pqxx::work statement(conn);
        pqxx::result resultSet = statement.exec("SELECT * FROM test");

        /*    
        std::cout << "Found " << resultSet.size() << " messages: " << std::endl;
        for (auto row: resultSet){
            std::cout << row[1].c_str() << std::endl;
        }
        */

        return resultSet[0][1].c_str();
    }
}