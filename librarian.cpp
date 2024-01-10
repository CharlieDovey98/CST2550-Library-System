#include "librarian.h"
#include <iostream>
#include <limits>
#include "book.h"
#include "member.h"

int memberID = 101;

// A derived class of the Person class. This class will inherit the members of the Person class.

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
    Alexa.printMemberDetails(memberID); // Print the members details that were just added to the system.
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
    Member *memberBorrowingBook = findMember(memberID);
    Book *bookToBorrow = findBook(bookID);

    if (memberBorrowingBook && bookToBorrow)
    {
        std::cout << "Member Name: " << memberBorrowingBook->getName() << std::endl;
        std::cout << "Member ID: " << memberBorrowingBook->getMemberID() << std::endl;
        std::cout << "Book Title: " << bookToBorrow->getBookName() << std::endl;
        std::cout << "Book ID: " << bookToBorrow->getBookID() << std::endl;

        time_t dueDate = time(nullptr) + (3 * 24 * 60 * 60); // dueDate in days.
        bookToBorrow->borrowBook(memberBorrowingBook, dueDate);
    }
}

void Librarian::returnBook(int memberID, int bookID){
    // cout memberID #### has returned bookID ####
}

void Librarian::displayBorrowedBooks(int memberID){
    
    Member *member = Alexa.findMember(memberID);
    if (member != nullptr) // If member is found, member is not equal to nullpointer.
    {
        std::vector<Book *> borrowedBooks = member->getBooksBorrowed();
        if (borrowedBooks.empty())
        {
            std::cout << "No books currently borrowed by member ID " << memberID << std::endl;
        }
        else
        {
            std::cout << "Borrowed books by:" << std::endl;
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