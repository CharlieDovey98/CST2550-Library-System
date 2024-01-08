#ifndef MEMBER_H
#define MEMBER_H

// The member.h header file.
#include <vector>
#include "person.h"
#include "book.h"

class Member : public Person
{
private:
    int memberID;
    std::vector<Book *> booksLoaned;

public:
    Member(int memberID, std::string name, std::string address, std::string email);
    std::string getMemberID() const;
    std::vector<Book *> getBooksBorrowed() const;
    void setBooksBorrowed(Book *book);
};

std::vector<Member> &getMemberList();

#endif // MEMBER_H