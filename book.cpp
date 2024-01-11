// Library Management System, book.cpp

//Include the header file of the book class.
#include "book.h"

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
};

std::string Book::getBookID() const{
    return std::to_string(bookID);
}

std::string Book::getBookName() const{
    return bookName;
}

std::string Book::getAuthorFirstName() const{
    return authorFirstName;
}

std::string Book::getAuthorLastName() const{
    return authorLastName;
}

time_t Book::getDueDate() const{
    return dueDate;
}

// Set the due date for 3 days from date of issue to the member.
void Book::setDueDate(time_t dueDate){
    this->dueDate = dueDate;
}

void Book::returnBook(int bookID, int memberID){
    std::cout << "Book ID " << bookID << " has been successfully returned by Member ID " << memberID << std::endl;
}

void Book::borrowBook(Member *borrower, time_t dueDate){
    this->borrower = borrower;
    setDueDate(dueDate);
    // Set the due date for dueDate days from the current date.
    borrower->setBooksBorrowed(this);
}

// This function returns a reference to the vector of book objects.
std::vector<Book> &getBookList(){
    // A vector to hold all of the book objects that will be added to the system.
    static std::vector<Book> bookList;
    return bookList;
}