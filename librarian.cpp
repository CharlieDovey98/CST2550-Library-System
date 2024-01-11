// Library Management System, librarian.cpp
// A derived class of the Person class. This class will inherit the members of the Person class.

// Include all the libraries for the code to run.
#include <iostream>
#include <algorithm>
#include <limits>
//Include the header files of the classes.
#include "librarian.h"
#include "member.h"
#include "book.h"

int memberID = 101;

Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary){
    this->staffID = staffID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
}

Librarian Alexa(1001, "Alexa A", "410 Terry Ave N, Seattle 98109, WA.", "reply@amazon.com", 100000);

void Librarian::printMemberDetails(int memberID){
    const std::vector<Member> &members = getMemberList();
    std::string memberIDToString = std::to_string(memberID);
    for (const Member &member : members)
    {
        if (std::string(member.getMemberID()) == memberIDToString)
        {
            std::cout << "Member ID: " << member.getMemberID() << ", "
                      << "Name: " << member.getName() << ", "
                      << "Address: " << member.getAddress() << ", "
                      << "Email: " << member.getEmail() << std::endl;
            return;
        }
    }
    std::cout << "Member with ID " << memberID << " not found." << std::endl;
}

void Librarian::addMember(){
    std::string name, address, email;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the member's name: ";
    std::getline(std::cin, name);
    // Validation.

    std::cout << "Enter the member's address: ";
    std::getline(std::cin, address);
    // Validation.

    std::cout << "Enter the member's email address: ";
    std::getline(std::cin, email);
    // Validation.

    Member newMember(memberID, name, address, email); // Create new Member object.
    std::cout << "\nNew member added\n" << std::endl;
    getMemberList().push_back(newMember); // Add new Member to the member list vector.
    Alexa.printMemberDetails(memberID);   // Print the members details that were just added to the system.
    std::cout << "\n########### Returning to the menu ###########\n";
    memberID += 1;
}

Member *Librarian::findMember(int memberID){
    std::vector<Member> &members = getMemberList();
    std::string memberIDAsAString = std::to_string(memberID);
    for (Member &member : members) // For all members in the members vector, check to see if the membersID matches the parameter bookID provided.
    {
        if (member.getMemberID() == memberIDAsAString)
        {
            return &member; // If the user input memberID matches a stored members memberID, return a pointer to the member.
        }
    }
    return nullptr; // Return nullptr if no member with the user input memberID is found.
}

Book *Librarian::findBook(int bookID){
    std::vector<Book> &books = getBookList();
    std::string bookIDAsAString = std::to_string(bookID);
    for (Book &book : books) // For all books in the books vector, check to see if the bookID matches the parameter bookID provided.
    {
        if (book.getBookID() == bookIDAsAString)
        {
            return &book; // If the user input bookID matches a stored books bookID, return a pointer to the book.
        }
    }
    return nullptr; // Return nullptr if no book with the user input bookID is found.
}

void Librarian::issueBook(int memberID, int bookID){
    Member *memberBorrowingBook = findMember(memberID);
    Book *bookToBorrow = findBook(bookID);

    if (memberBorrowingBook && bookToBorrow){
        std::cout << "Member Name: " << memberBorrowingBook->getName() << std::endl;
        std::cout << "Member ID: " << memberBorrowingBook->getMemberID() << std::endl;
        std::cout << "Book Title: " << bookToBorrow->getBookName() << std::endl;
        std::cout << "Book ID: " << bookToBorrow->getBookID() << std::endl;

        time_t dueDate = time(nullptr) + (3 * 24 * 60 * 60); // dueDate calculation in days.
        std::cout << dueDate << std::endl;
        bookToBorrow->borrowBook(memberBorrowingBook, dueDate);
    }
}

void Librarian::returnBook(int memberID, int bookID){
    // Find the member and the book by their IDs
    Member* memberReturningBook = findMember(memberID);
    if (!memberReturningBook) {
        std::cout << "Member with ID " << memberID << " not found." << std::endl;
        return;
    }

    Book* bookBeingReturned = findBook(bookID);
    if (!bookBeingReturned) {
        std::cout << "Book with ID " << bookID << " not found." << std::endl;
        return;
    }

    // Attempt to find the book in the member's list of borrowed books
    auto& borrowedBooks = memberReturningBook->getBooksBorrowedReference();
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookBeingReturned);

    // If the book is found in the member's borrowed books.
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);// Remove the book from the member's borrowed books.
        calculateFine(memberID, bookBeingReturned); // Calculate the fine for the member if the book is past its due date.
        bookBeingReturned->returnBook(bookID, memberID); // Return the book.
    } else {
        std::cout << "Member ID " << memberID << " did not borrow book ID " << bookID << std::endl;
    }
}

void Librarian::displayBorrowedBooks(int memberID){

    Member *member = Alexa.findMember(memberID);
    if (member != nullptr) // If member is not equal to nullpointer.
    {
        std::vector<Book *> borrowedBooks = member->getBooksBorrowed();
        if (borrowedBooks.empty())
        {
            std::cout << "No books currently borrowed by member ID " << memberID << std::endl;
        }
        else
        {
            std::cout << "\nThe books borrowed by:" << std::endl;
            Alexa.printMemberDetails(memberID);
            for (Book *book : borrowedBooks)
            {
                std::cout << "\nBook ID: " << book->getBookID() << ", "
                          << "Name: " << book->getBookName() << ", "
                          << "Author: " << book->getAuthorFirstName() << " " << book->getAuthorLastName() << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Member with ID " << memberID << " not found." << std::endl;
    }
}

// A function to Calculate fine if the book is overdue.
void Librarian::calculateFine(int memberID, Book* bookBeingReturned){
    time_t currentTime = time(nullptr);
    std::cout << "Current time " << currentTime << std::endl;
    if (currentTime > bookBeingReturned->getDueDate()) // Need to adapt the calculation for the fine.
    {
        double daysLate = difftime(currentTime, bookBeingReturned->getDueDate()) / (60 * 60 * 24);
        double fine = daysLate * 1;
        std::cout << "Member with ID: " << memberID << std::endl;
        std::cout << "Days late " << daysLate << "    Fine " << fine << std::endl;
        std::cout << "Book is returned late. Fine due: $" << fine << std::endl;
    }
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