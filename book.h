#ifndef BOOK_H
#define BOOK_H

// The book.h header file.
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "member.h"

class Book{
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    time_t dueDate;
    class Member *borrower;

public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
    std::string getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    time_t getDueDate() const;
    void setDueDate(time_t dueDate);
    void returnBook();
    void borrowBook(Member *borrower, time_t dueDate);
};

std::vector<Book>& getBookList();

#endif // BOOK_H