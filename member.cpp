#include "member.h"

// A derived class of the Person class. This class will inherit the members of the Person class.

// Construct a member using the person class.
Member::Member(int memberID, std::string name, std::string address, std::string email){
    this->memberID = memberID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
}

std::string Member::getMemberID() const{
    return std::to_string(memberID);
}

std::vector<Book *> Member::getBooksBorrowed(){
    return booksLoaned;
}

std::vector<Book *>&  Member::getBooksBorrowedReference(){
    return booksLoaned;
}

void Member::setBooksBorrowed(Book *book){
    // user prompt, input and validation to be handled within the main.cpp file?
    booksLoaned.push_back(book);
}

// This function returns a reference to the vector of member objects.
std::vector<Member> &getMemberList(){
    // A vector to hold all of the member objects that will be added to the system.
    static std::vector<Member> memberList;
    return memberList;
}