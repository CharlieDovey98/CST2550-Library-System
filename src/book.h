// Library Management System, The book.h header file.
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "member.h"

// Declaring the book class' variables, methods and identifiers.
class Book{
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    time_t dueDate;
    class Member *borrower;
    bool isIssued;

public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName, bool isIssued);
    std::string getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    time_t getDueDate() const;
    void setDueDate(time_t dueDate);
    void returnBook(int bookID, int memberID);
    void borrowBook(Member *borrower, time_t dueDate);
    bool isBookIssued() const;
    void setBookAsIssued(bool bookIssued);
};

std::vector<Book>& getBookList();

#endif // BOOK_H