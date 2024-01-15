// Library Management System, book.cpp

//Include the header file of the book class.
#include "book.h"

// The constructor of the book object.
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName, bool isIssued){
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
    this->isIssued = isIssued;
};

// An accessor method to return the book id of a book object as a string.
std::string Book::getBookID() const{
    return std::to_string(bookID);
}

// An accessor method to return the book name of a book object.
std::string Book::getBookName() const{
    return bookName;
}

// An accessor method to return the authors first name of a book object.
std::string Book::getAuthorFirstName() const{
    return authorFirstName;
}

// An accessor method to return the authors last name of a book object.
std::string Book::getAuthorLastName() const{
    return authorLastName;
}

// An accessor method to return the due date of a book object.
time_t Book::getDueDate() const{
    return dueDate;
}

// An accessor method to return the boolean value of a book object. 1 or True depicts its on loan, 0 or False depicts it is available.
bool Book::isBookIssued() const{
    return isIssued;
}

// A mutator method to se the boolean value of a book object to show its available or out on loan.
void Book::setBookAsIssued(bool bookIssued){
    this->isIssued = bookIssued;
}

// A mutator method to set the due date for the book being issued to the member.
void Book::setDueDate(time_t dueDate){
    this->dueDate = dueDate;
}

// A method which sets a book object as returned and displays a print statement to the console depicting the successfulful return.
void Book::returnBook(int bookID, int memberID){
    setBookAsIssued(true);
    std::cout << "Book ID " << bookID << " has been successfully returned by Member ID " << memberID << std::endl;
}

// A method which calls the setDueDate function to attain the due date of a book object being loaned. This function also the book being borrowed to a member object.
void Book::borrowBook(Member *borrower, time_t dueDate){
    this->borrower = borrower;
    setDueDate(dueDate);
    borrower->setBooksBorrowed(this);
}

// An accessor method which returns a reference to the vector of book objects.
std::vector<Book> &getBookList(){
    // A vector to hold all of the book objects that will be added to the system.
    static std::vector<Book> bookList;
    return bookList;
}