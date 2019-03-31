#ifndef __ENTITY_HPP_
#define __ENTITY_HPP_

#include<string>
#include<memory>
#include<boost/python.hpp>


namespace zpr { 

class Entity {
  public:
    Entity(const long id) : id(id) {};
    virtual std::string mapEntityToSQLInsert() = 0;
  private:
    long id;
};

}

#endif //_ENTITY_HPP_