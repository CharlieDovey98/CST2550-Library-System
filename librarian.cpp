#include <iostream>
#include "librarian.h"

// A derived class of the Person class. This class will inherit the members of the Person class.

Librarian::Librarian(int staffID, std::string name, std::string address, std::string email, int salary)
{
    this->staffID = staffID;
    this->setName(name);
    this->setAddress(address);
    this->setEmail(email);
    this->salary = salary;
};

void Librarian::addMember(){
// cout enter them members name: 
// cout enter the persons email:
// cout enter the persons address: 
// validation
// create a memberID 
// assign information to member
// cout this person has been added as a member, here are their details:
};

void Librarian::issueBook(int memberID, int bookID){
// bookID #### has been lent out to memberID ####
};

void Librarian::returnBook(int memberID, int bookID){
// cout memberID #### has returned bookID ####
};

void Librarian::displayBorrowedBooks(int memberID){
// cout here are the borrowed books by this member: 
};

void Librarian::calculateFine(int memberID){
// days past due * $3
// cout there is a fine with this return: $4.00
};

int Librarian::getStaffID(){
    return staffID;
};

void Librarian::setStaffID(int staffID){
    this->staffID = staffID;
};

int Librarian::getSalary(){
    return salary;
};

void Librarian::setSalary(int salary){
    this->salary = salary;
};