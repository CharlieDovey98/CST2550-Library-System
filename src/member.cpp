// Library Management System, member.cpp
// A derived class of the Person class. This class will inherit the members of the Person class.

//Include the header file of the member class.
#include "member.h"

// The constructor of the member object, using the person class.
Member::Member(int memberID, std::string name, std::string address, std::string email){
    this->memberID = memberID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
}

// An accessor method which returns the member id as a string of a member object.
std::string Member::getMemberID() const{
    return std::to_string(memberID);
}

// An accessor method which returns a pointer to the books loaned vector of a specific member, stored within the member class.
std::vector<Book *> Member::getBooksBorrowed(){
    return booksLoaned;
}

// An accessor method which returns a reference to the books loaned vector of a member stored within the books class.
std::vector<Book *>&  Member::getBooksBorrowedReference(){
    return booksLoaned;
}

// A mutator method to push back a book object into the book vector stored in the book class.
void Member::setBooksBorrowed(Book *book){
    booksLoaned.push_back(book);
}

// An accessor function which returns a reference to the vector of member objects.
std::vector<Member> &getMemberList(){
    // A vector to hold all of the member objects that will be added to the system.
    static std::vector<Member> memberList;
    return memberList;
}