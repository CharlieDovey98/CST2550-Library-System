#include "librarian.h"

// A derived class of the Person class. This class will inherit the members of the Person class.

Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary){
    this->staffID = staffID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
}

void Librarian::addMember(Member &newMember){
    getMemberList().push_back(newMember); // Add new Member to the member list vector.
}

Member *findMember(int memberID){
    std::vector<Member> &members = getMemberList();
    std::string memberIDAsAString = std::to_string(memberID);
    for (Member &member : members) // For all members in the members vector, check to see if the membersID matches the parameter bookID provided.
    {
        if (member.getMemberID() == memberIDAsAString)
        {
            return &member; // Return a pointer to the member. maybe needs to return true instead?
        }
    }
    return nullptr; // Return nullptr if no member with the given ID is found.
}

Book *findBook(int bookID){
    std::vector<Book> &books = getBookList();
    std::string bookIDAsAString = std::to_string(bookID);
    for (Book &book : books) // For all books in the books vector, check to see if the bookID matches the parameter bookID provided.
    {
        if (book.getBookID() == bookIDAsAString)
        {
            return &book; // Return a pointer to the book. maybe needs to return true instead?
        }
    }
    return nullptr; // Return nullptr if no book with the given ID is found.
}

void Librarian::issueBook(int memberID, int bookID){
    findMember(memberID);
    findBook(bookID);
    time_t nowPlusThreeDays = time(nullptr) + (3 * 24 * 60 * 60); // dueDate in days.
   // book->borrowBook(findMember(memberID), nowPlusThreeDays);
}

void Librarian::returnBook(int memberID, int bookID){
    // cout memberID #### has returned bookID ####
}

void Librarian::displayBorrowedBooks(int memberID){
    // cout here are the borrowed books by this member:
}

void Librarian::calculateFine(int memberID){
    // days past due * $3
    // cout there is a fine with this return: $4.00
}

int Librarian::getStaffID(){
    return staffID;
}

void Librarian::setStaffID(int staffID){
    this->staffID = staffID;
}

int Librarian::getSalary(){
    return salary;
}

void Librarian::setSalary(int salary){
    this->salary = salary;
}