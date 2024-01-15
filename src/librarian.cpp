// Library Management System, librarian.cpp
// A derived class of the Person class. This class will inherit the members of the Person class.

// Include all the libraries for the code to run.
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <limits>
#include <regex>
//Include the header files of the classes.
#include "librarian.h"
#include "member.h"
#include "book.h"

int memberID = 101;

// The constructor for the librarian object.
Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary){
    this->staffID = staffID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
}

Librarian Alexa(1001, "Alexa A", "Amazon Ave", "reply@amazon.com", 100000);

// A function to print out out the members details. This function uses the get methods from the member class.
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

// A function to add members to the system and store them in memory.
void Librarian::addMember(){
    std::string memberName, memberAddress, memberEmail;
    // Below are Regex pattern expressions to validate the user input.
    std::regex nameRegexPattern(R"([a-zA-Z\s]+)");; // A member's name can only be characters and spaces.
    std::regex addressRegexPattern("^[0-9A-Za-z ,.'-]+$"); // A member's address can contain numbers characters and specific symbols.
    // A member's email has to follow the conventional email format, a set of characters, symbols and numbers followed by an @ sign. Then the same format, followed by a . with at least 2 characters following the .
    std::regex emailRegexPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"); 

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the member's name: ";
    std::getline(std::cin, memberName);
    // A validation check using a while loop, guard statement.
    while (!std::regex_match(memberName, nameRegexPattern)){
        std::cout << "A member's name cannot be blank and must only comprise of characters: ";
        std::getline(std::cin, memberName);
    }
    
    std::cout << "Enter the member's address: ";
    std::getline(std::cin, memberAddress);
    // A validation check using a while loop, guard statement.
    while (!std::regex_match(memberAddress, addressRegexPattern)){
        std::cout << "A member's address cannot be blank, however can contain numbers, letters and (,.'-) : ";
        std::getline(std::cin, memberAddress);
    }

    std::cout << "Enter the member's email address: ";
    std::getline(std::cin, memberEmail);
    // A validation check using a while loop, guard statement.
    while (!std::regex_match(memberEmail, emailRegexPattern)){
        std::cout << "A member's email must follow the conventional email format (e.g. NewMember@gmail.co.uk)" << std::endl;
        std::cout << "Enter the member's email address: ";
        std::getline(std::cin, memberEmail);
    }

    Member newMember(memberID, memberName, memberAddress, memberEmail); // Create new Member object.
    std::cout << "\nNew member added."
              << std::endl;
    getMemberList().push_back(newMember); // Add new Member to the member list vector.
    Alexa.printMemberDetails(memberID);   // Print the members details that were just added to the system.
    memberID += 1;
}

// A function to find a member by id, within the member vector stored in memory.
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

// A function to find a book by its id, within the book vector stored in memory.
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

// A function to issue a book to a member using memberid and bookid.
void Librarian::issueBook(int memberID, int bookID){
    Member *memberBorrowingBook = findMember(memberID);
    Book *bookToBorrow = findBook(bookID);

    if (bookToBorrow->isBookIssued())
    {
        std::cout << "The book with ID " << bookID << " is already issued and cannot be borrowed at the moment." << std::endl;
        return;
    }
    else
    {
        std::cout << "\nMember Name: " << memberBorrowingBook->getName() << std::endl;
        std::cout << "Member ID: " << memberBorrowingBook->getMemberID() << std::endl;
        std::cout << "Book Title: " << bookToBorrow->getBookName() << std::endl;
        std::cout << "Book ID: " << bookToBorrow->getBookID() << std::endl;

        time_t currentTime = time(nullptr); // A calculation to attain the current system time.
        std::cout << "The book's issue date is: " << ctime(&currentTime);

        time_t dueDate = currentTime + (3 * 24 * 60 * 60); // A calculation to attain the current system time + 3 days to set the loan period for 3 days.
        std::cout << "The book's due date is: " << ctime(&dueDate);

        bookToBorrow->setBookAsIssued(true); // The book issued boolean will now be set to true so other users cannot loan it.
        bookToBorrow->borrowBook(memberBorrowingBook, dueDate); // Call borrowBook and pass the dueDate and member for it to be set.
        std::cout << "Book ID " << bookID << " has been successfully issue to Member ID " << memberID << std::endl;
    }
}

// A function to return a book from a member. this will change the book objects boolean value from true back to false, allowing it to be rented again.
void Librarian::returnBook(int memberID, int bookID){
    Member* memberReturningBook = findMember(memberID); // Find the member from the parameter given when calling the function.
    if (!memberReturningBook) {
        std::cout << "Member with ID " << memberID << " not found." << std::endl;
        return;
    }

    Book* bookBeingReturned = findBook(bookID); // Find the book from the parameter given when calling the function.
    if (!bookBeingReturned) {
        std::cout << "Book with ID " << bookID << " not found." << std::endl;
        return;
    }

    // Attempt to find the book in the member's list of borrowed books.
    auto& borrowedBooks = memberReturningBook->getBooksBorrowedReference();
    // Use auto to find the book within borrowedBooks. 
    auto bookSearch = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookBeingReturned);

    // If the book is found in the member's borrowed books.
    if (bookSearch != borrowedBooks.end()) {
        borrowedBooks.erase(bookSearch);// Remove the book from the member's borrowed books.
        calculateFine(memberID, bookBeingReturned); // Calculate the fine for the member if the book is past its due date.
        bookBeingReturned->returnBook(bookID, memberID); // Return the book.
        bookBeingReturned->setBookAsIssued(false); // set the bookIssued boolean back to false allowing it to be loaned by another member.
    } else {
        std::cout << "Member ID " << memberID << " did not borrow book ID " << bookID << std::endl;
    }
}

// A function to display all borrowed books by a member using their memberid.
void Librarian::displayBorrowedBooks(int memberID){
    Member *member = Alexa.findMember(memberID);
    if (member != nullptr) // If member is not equal to nullpointer.
    {
        std::vector<Book *> borrowedBooks = member->getBooksBorrowed(); // Create a local vector to store the members books.
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
                time_t date = book->getDueDate();
                std::cout << "\nBook ID: " << book->getBookID() << ", "
                          << "Name: " << book->getBookName() << ", "
                          << "Author: " << book->getAuthorFirstName() << " " << book->getAuthorLastName() << ", "
                          << "This book is due: " << ctime(&date);
            }
        }
    }
    else
    {
        std::cout << "Member with ID " << memberID << " not found." << std::endl;
    }
}

// A function to Calculate a fine if the book is overdue, past the three day loan period.
void Librarian::calculateFine(int memberID, Book* bookBeingReturned){
    time_t currentTime = time(nullptr); // The current system time.

    // Add the line of code below to set the fine to being past the due date.
    // time_t currentTimePlus10 = currentTime + (10 * 24 * 60 * 60);

    std::cout << "Current time of return: " << ctime(&currentTime) << std::endl;
    if (currentTime > bookBeingReturned->getDueDate()){
        double daysLate = difftime(currentTime, bookBeingReturned->getDueDate()) / (60 * 60 * 24);
        double fine = daysLate * 1;

        std::cout << "The book is " << daysLate << "days late, incuring a fine of " << fine << std::endl;
        std::cout << "Fine due: £" << floor(fine) << std::endl;
        std::cout << "MemberID: " << memberID << "returning: " << bookBeingReturned << std::endl;
    }
    std::cout << "You are within the books due date, so you will not incur a fine" << std::endl;
}

// An accessor method to attain the staff id of a librarian object.
int Librarian::getStaffID(){
    return staffID;
}

// A mutator method to set the staff id of a librarian object.
void Librarian::setStaffID(int staffID){
    this->staffID = staffID;
}

// An accessor method to attain the salary of a librarian object.
int Librarian::getSalary(){
    return salary;
}

// A mutator method to set the librarian objects salary.
void Librarian::setSalary(int salary){
    this->salary = salary;
}