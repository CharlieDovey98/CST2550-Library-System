#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "person.h"
#include "book.h"
#include "member.h"
#include "librarian.h"

Librarian Alexa(1001, "Alexa A", "410 Terry Ave N, Seattle 98109, WA.", "reply@amazon.com", 100000);
void librarianPortal()
{
    std::cout << "Welcome librarian: " << Alexa.getName() << ", ID:" << Alexa.getStaffID() << "." << std::endl;
}

void startMenu()
{
    int choice = 0;

    std::cout << "\nPlease choose from the following options:"
              << "\n    [1] Add a member."
              << "\n    [2] View a member's borrowed books."
              << "\n    [3] Issue a book."
              << "\n    [4] Return a book."
              << "\n    [5] Exit the system." << std::endl;
    do{
        std::cout << "\nPlease enter your choice as a number: ";
        std::cin >> choice;

        // Check if input is not an integer or is out of range
        if (std::cin.fail() || choice < 1 || choice > 5)
        {
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    } while (true);
}

int main(void)
{
    std::cout << "\nLibrary Management System V1.\n"
              << std::endl;
    librarianPortal();
    startMenu();
}
