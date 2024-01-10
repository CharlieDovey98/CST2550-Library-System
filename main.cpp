#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include "person.h"
#include "book.h"
#include "member.h"
#include "librarian.h"

int memberID = 101;
bool bookDataFileFound = false;

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

        // Validation checks using a do while loop.
        // If the input is not an integer or is out of range get a new input from the user.
        if (std::cin.fail() || menuChoice < 1 || menuChoice > 5)
        {
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return menuChoice; // Once a correct input has been attained, return the input.
        }
    } while (true);
}

void printMemberDetails(int memberID)
{
    const std::vector<Member> &members = getMemberList();
    for (const Member &member : members)
    {
        if (std::string(member.getMemberID()) == std::to_string(memberID))
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

void attainTheLibraryInformationFile()
{
    std::string fileName;
    std::ifstream inputFile;

    do
    {
        std::cout << "Please enter the book data filename for the library management system\n(e.g. librarybooks.csv): " << std::endl;
        std::getline(std::cin, fileName);

        // Validation checks using a do while loop.
        // If the input is not an integer or is out of range get a new input from the user.
        if (std::cin.fail()) // Validation if the file exists?.
        {
            std::cout << "Invalid filename. enter the book data filename for the library management system (e.g. librarybooks.csv): " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            bookDataFileFound = true;
            break; // Once a correct input has been attained, break.
        }
    } while (true);

    std::string line = "";
    inputFile.open(fileName);
    std::getline(inputFile, line); // Attain the first line from the document, the cell headings.
    line = "";                     // Discard the first headings line, as we only want to add books to the book vector.

    while (std::getline(inputFile, line))
    {
        int bookID;
        std::string bookName;
        std::string pageCount;
        std::string authorFirstName;
        std::string authorLastName;
        std::string bookType;
        std::string temporaryString;

        std::stringstream inputString(line);

        getline(inputString, temporaryString, ','); // allocating bookID to a temporary string.
        bookID = atoi(temporaryString.c_str());     // Converting bookId to an integer.
        getline(inputString, bookName, ',');
        getline(inputString, pageCount, ',');
        getline(inputString, authorFirstName, ',');
        getline(inputString, authorLastName, ',');
        getline(inputString, bookType, ',');

        std::string line = "";
        Book newBook(bookID, bookName, authorFirstName, authorLastName);
        getBookList().push_back(newBook);
    }
    std::cout << "\nBooks added successfully\n";
}

void printBooks()
{
    const std::vector<Book> &books = getBookList(); // Use the getBookList() to access the vector of books
    for (const Book &book : books)                  // For loop through to print each book for testing purposes. This is not used in the main funcionality of the program.
    {
        std::cout << "Book ID: " << book.getBookID() << ", "
                  << book.getBookName() << ", "
                  << book.getAuthorFirstName() << ", "
                  << book.getAuthorLastName() << std::endl;
    }
}

int main(void)
{
    while (true)
    {

        int menuChoice;

        std::cout << "\nLibrary Management System V1.\n"
                  << std::endl;
        librarianPortal();

        if (bookDataFileFound == false)
        {
            // call the function to attain
            attainTheLibraryInformationFile();
            printBooks();
        }

        menuChoice = startMenu(menuChoice);
        // userInputHandling(menuChoice);

        if (menuChoice == 1) // Add a member functionality.
        {
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
            Alexa.addMember(newMember);                       // Using librarian Alexa to add a new member.

            std::cout << "\nNew member added:\n";
            printMemberDetails(memberID); // Print the members details that were just added to the system.
            std::cout << "\nReturning to the menu\n";
            memberID += 1;
        }

        if (menuChoice == 2) // View a members borrowed books functionality.
        {
            int memberIDForBorrowedBooks;

            std::cout << "Please enter the member's ID to view their currently borrowed books: ";
            std::cin >> memberIDForBorrowedBooks;

            // Validation checks using a do while loop.
            // If the input is not an integer or is out of range get a new input from the user.
            while (std::cin.fail()) // || member id does not exist?
            {
                std::cout << "Invalid memberID. Please enter the memberID in numbers, of a registered member." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter the member's ID to view their currently borrowed books: ";
                std::cin >> memberIDForBorrowedBooks;
            }
            Member *member = Alexa.findMember(memberIDForBorrowedBooks);
            if (member != nullptr) // If member is found, member is not equal to nullpointer.
            {
                std::vector<Book *> borrowedBooks = member->getBooksBorrowed();
                if (borrowedBooks.empty())
                {
                    std::cout << "No books currently borrowed by member ID " << memberIDForBorrowedBooks << std::endl;
                }
                else
                {
                    std::cout << "Borrowed books by member ID " << memberIDForBorrowedBooks << ":" << std::endl;
                    for (Book *book : borrowedBooks)
                    {
                        std::cout << "Book ID: " << book->getBookID() << ", "
                                  << "Name: " << book->getBookName() << ", "
                                  << "Author: " << book->getAuthorFirstName() << " " << book->getAuthorLastName() << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Member with ID " << memberIDForBorrowedBooks << " not found." << std::endl;
            }
            // look at members member.cpp look at getBooksBorrowed() member.cpp
            std::cout << "member details here?";
        }

        if (menuChoice == 3) // Issue a book to a member functionality.
        {
            int memberIDToIssueABook, bookIDToIssueABook;
            bool memberIDBoolean, bookIDBoolean;

            std::cout << "Please enter the memberID of the member that wants to borrow a book: ";
            std::cin >> memberIDToIssueABook;

            // Validation checks using a do while loop.
            // If the input is not an integer or is out of range get a new input from the user.
            while (std::cin.fail()) // || findMember(memberIDToIssueABook) == nullptr) // || member id does not exist?
            {
                std::cout << "Invalid memberID. Please enter the memberID in numbers, of a registered member." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter the memberID of the member that wants to borrow a book: ";
                std::cin >> memberIDToIssueABook;
            }
            memberIDBoolean = true;

            std::cout << "Please enter the bookID of the book that is being issued out: ";
            std::cin >> bookIDToIssueABook;

            // Validation checks using a do while loop.

            // If the input is not an integer or is out of range get a new input from the user.
            while (std::cin.fail()) // || findBook(bookIDToIssueABook) == nullptr) // || member id does not exist?
            {
                std::cout << "Invalid bookID. Please enter the bookID in numbers, of a in stock library book." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter the bookID of the book that is being issued out: ";
                std::cin >> bookIDToIssueABook;
            }

            bookIDBoolean = true;

            if (memberIDBoolean && bookIDBoolean)
            {
                Alexa.issueBook(memberIDToIssueABook, bookIDToIssueABook);
            }
        }

        if (menuChoice == 4) // Return a book from a member functionality.
        {
        }

        if (menuChoice == 5) // Exit the system functionality.
        {
            std::cout << "System Exiting" << std::endl;
            exit(0);
        }
    }
}