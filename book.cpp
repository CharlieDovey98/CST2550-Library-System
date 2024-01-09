#include <iostream>
#include "book.h"

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
};

std::string Book::getBookID() const{
    return std::to_string(bookID);
};

std::string Book::getBookName() const{
    return bookName;
};

std::string Book::getAuthorFirstName() const{
    return authorFirstName;
};

std::string Book::getAuthorLastName() const{
    return authorLastName;
};

time_t Book::getDueDate() const{
    return dueDate;
};

void Book::setDueDate(time_t dueDate){
    this->dueDate = dueDate;
    // set the due date for 3 days from date of issue to the member.
};

void Book::returnBook(){
// cout enter the bookID that is being returned: 
// get due date
// is it past the due date
// calculateFine()
// this book has been returned
};

void Book::borrowBook(Member *borrower, time_t dueDate){
// setBooksBorrowed()
// setDueDate()
};

// This function returns a reference to the vector of book objects.
std::vector<Book> &getBookList()
{
    // A vector to hold all of the book objects that will be added to the system.
    static std::vector<Book> bookList;
    return bookList;
}