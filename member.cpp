#include <iostream>
#include "member.h"

// A derived class of the Person class. This class will inherit the members of the Person class.

// Construct a member using the person class.
Member::Member(int memberID, std::string name, std::string address, std::string email){
    this->memberID = memberID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
};

std::string Member::getMemberID(){
    return std::to_string(memberID);
};

std::vector<Book*> Member::getBooksBorrowed(){
    return booksLoaned;
};

void Member::setBooksBorrowed(Book* book){
    // user prompt, input and validation to be handled within the main.cpp file?
    booksLoaned.push_back(book);
};