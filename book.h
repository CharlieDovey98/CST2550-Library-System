#ifndef BOOK_H
#define BOOK_H

// The book.h header file.
#include <string>
#include <ctime>

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
    std::string getBookID();
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
    time_t getDueDate();
    void setDueDate(time_t dueDate);
    void returnBook();
    void borrowBook(Member *borrower, time_t dueDate);
};

#endif // BOOK_H