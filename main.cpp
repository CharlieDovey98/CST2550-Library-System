#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "person.h"
#include "book.h"
#include "member.h"
#include "librarian.h"

int memberID = 101;

Librarian Alexa(1001, "Alexa A", "410 Terry Ave N, Seattle 98109, WA.", "reply@amazon.com", 100000);
void librarianPortal()
{
    std::cout << "Welcome librarian: " << Alexa.getName() << ", ID:" << Alexa.getStaffID() << "." << std::endl;
}

int startMenu(int menuChoice)
{
    std::cout << "\nPlease choose from the following options:"
              << "\n    [1] Add a member."
              << "\n    [2] View a member's borrowed books."
              << "\n    [3] Issue a book."
              << "\n    [4] Return a book."
              << "\n    [5] Exit the system." << std::endl;
    do
    {
        std::cout << "\nPlease enter your choice as a number: ";
        std::cin >> menuChoice;

        // Check if input is not an integer or is out of range
        if (std::cin.fail() || menuChoice < 1 || menuChoice > 5)
        {
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return menuChoice;
        }
    } while (true);
}

void printMemberDetails(int memberID) {
    const std::vector<Member>& members = getMemberList();
    for (const Member& member : members) {
        if (std::string(member.getMemberID()) == std::to_string(memberID)) {
            std::cout << "Member ID: " << member.getMemberID() << ", "
                      << "Name: " << member.getName() << ", "
                      << "Address: " << member.getAddress() << ", "
                      << "Email: " << member.getEmail() << std::endl;
            return;
        }
    }
    std::cout << "Member with ID " << memberID << " not found." << std::endl;
}

void userInputHandling(int userChoice)
{
}

int main(void)
{
    int menuChoice;

    std::cout << "\nLibrary Management System V1.\n"
              << std::endl;
    librarianPortal();
    menuChoice = startMenu(menuChoice);
    // userInputHandling(menuChoice);
    if (menuChoice == 1)
    {
        
        std::string name, address, email;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter the member's name: ";
        std::getline(std::cin, name);

        std::cout << "Enter the member's address: ";
        std::getline(std::cin, address);

        std::cout << "Enter the member's email address: ";
        std::getline(std::cin, email);

        Member newMember(memberID, name, address, email); // Create new Member object.
        getMemberList().push_back(newMember);             // Add new Member to the member list vector.

        std::cout << "\nNew member added:\n";
        printMemberDetails(memberID);
        std::cout << "\nReturning to the menu\n";
        memberID += 1;
        main();
    }
    if (menuChoice == 2)
    {
    }
    if (menuChoice == 3)
    {
    }
    if (menuChoice == 4)
    {
    }
    if (menuChoice == 5)
    {
        std::cout << "System Exiting" << std::endl;
        exit(0);
    }
}
