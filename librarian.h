#ifndef LIBRARIAN_H
#define LIBRARIAN_H

// The librarian.h header file.
#include <iostream>
#include <ctime>
#include "person.h"
#include "member.h"
#include "book.h"

class Librarian : public Person{
private:
    int staffID;
    int salary;

public:
    Librarian(int staffID, std::string name, std::string address, std::string email, int salary);
    void addMember();
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calculateFine(int memberID);
    int getStaffID();
    void setStaffID(int staffID);
    int getSalary();
    void setSalary(int salary);
    Member* findMember(int memberID);
    void printMemberDetails(int memberID);
};

// Declare Alexa as an external variable so it can be called in the main.cpp file.
extern Librarian Alexa;

#endif // LIBRARIAN_H