#include <iostream>
#include "book.h"

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
};

std::string Book::getBookID(){
    return std::to_string(bookID);
};

std::string Book::getBookName(){
    return bookName;
};

std::string Book::getAuthorFirstName(){
    return authorFirstName;
};

std::string Book::getAuthorLastName(){
    return authorLastName;
};

time_t Book::getDueDate(){
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