// Library Management System, The member.h header file.
#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>
#include "person.h"

// Forward declaration to fix any circular dependancies, causing compiling errors.
class Book;

class Member : public Person{
private:
    int memberID;
    std::vector<Book *> booksLoaned;

public:
    Member(int memberID, std::string name, std::string address, std::string email);
    std::string getMemberID() const;
    std::vector<Book *> getBooksBorrowed();
    std::vector<Book *>& getBooksBorrowedReference();
    void setBooksBorrowed(Book *book);
};

std::vector<Member> &getMemberList();

#endif // MEMBER_H