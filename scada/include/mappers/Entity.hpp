#ifndef __ENTITY_HPP_
#define __ENTITY_HPP_

#include<string>
#include<memory>
#include<boost/python.hpp>


namespace zpr { 

class Entity {
  public:
    Entity(const long id) : id(id) {};
    virtual const std::string mapEntityToSQLInsert() const {
      return std::string("");
    }
  protected:
    long id;
};

}

#endif //_ENTITY_HPP_