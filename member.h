#ifndef MEMBER_H
#define MEMBER_H

// The member.h header file.
#include <vector>
#include "person.h"
#include "book.h"

class Member : public Person{
private:
    int memberID;
    std::vector<Book *> booksLoaned;

public:
    Member(int memberID, std::string name, std::string address, std::string email);
    std::string getMemberID();
    std::vector<Book *> getBooksBorrowed();
    void setBooksBorrowed(Book *book);
};

#endif // MEMBER_H