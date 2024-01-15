// Library Management System, person.cpp
// The base class. This class will be the parent class to librarian and member class.

// Include the input output library for the code to run.
#include <iostream>
//Include the header file of the person class.
#include "person.h"

// An accessor method to return the name of a person object.
std::string Person::getName() const{
    return name;
}

// A mutator method to set the name of a person object.
void Person::setName(std::string name){
    this->name = name;
}

// An accessor method to attain the address of a person object.
std::string Person::getAddress() const{
    return address;
}

// A mutator method to set the address of a person object. 
void Person::setAddress(std::string address){
    this->address = address;
}

// An accessor method used to attain the email of a person object.
std::string Person::getEmail() const{
    return email;
}

// A mutator method to set the email of a person object.
void Person::setEmail(std::string email){
    this->email = email;
}