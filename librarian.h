#ifndef LIBRARIAN_H
#define LIBRARIAN_H

// The librarian.h header file.
#include "person.h"
#include "member.h"

class Librarian: public Person{
    private:
        int staffID;
        int salary;
    public:
        Librarian(int staffID, std::string name, std::string address, std::string email, int salary);
        void addMember(Member &newMember);
        void issueBook(int memberID, int bookID);
        void returnBook(int memberID, int bookID);
        void displayBorrowedBooks(int memberID);
        void calculateFine(int memberID);
        int getStaffID();
        void setStaffID(int staffID);
        int getSalary();
        void setSalary(int salary);
};

#endif //LIBRARIAN_H