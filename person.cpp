#include <iostream>
#include "person.h"

// The base class. This class will be the parent class to librarian and member class.

std::string Person::getName() const{
    return name;
};

void Person::setName(std::string &name){
    this->name = name;
};

std::string Person::getAddress() const{
    return address;
};

void Person::setAddress(std::string &address){
    this->address = address;
};

std::string Person::getEmail() const{
    return email;
};

void Person::setEmail(std::string& email){
    this->email = email;
};