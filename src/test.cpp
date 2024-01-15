#define CATCH_CONFIG_MAIN
// Include all the libraries for the code to run.
#include "catch.hpp"
#include "person.h"
#include "book.h"
#include "member.h"
#include "librarian.h"

// Initialising objects that will be tested using the test cases below.
Librarian librarianSiri(9998, "Siri", "Apple Ave", "sirihelpline@apple.com", 100000);
Librarian librarianAlexa(9999, "librarianAlexa", "Amazon Ave", "librarianalexahelpline@aws.com", 100000);
Member member(101, "David G", "Deadend drive", "davidgamez@live.mdx.ac.uk");
Book book(100, "The Test Book", "Testing", "Author", false);
Person person;

// Test case for all accessor functions in the Book class.
TEST_CASE("Book get functionality", "[Book]"){
    REQUIRE(book.getBookID() == "100");
    REQUIRE(book.getBookName() == "The Test Book");
    REQUIRE(book.getAuthorFirstName() == "Testing");
    REQUIRE(book.getAuthorLastName() == "Author");
    REQUIRE(book.isBookIssued() == false);
}

// Test case for all accessor functions in the member class.
TEST_CASE("Member get functionality", "[Member]"){
    REQUIRE(member.getMemberID() == "101");
    REQUIRE(member.getName() == "David G");
    REQUIRE(member.getAddress() == "Deadend drive");
    REQUIRE(member.getEmail() == "davidgamez@live.mdx.ac.uk");
    // Adding wrong test cases as an example.
    // Uncomment the below REQUIRE statements to see the test fail in the Catch2tests.exe
    // REQUIRE(member.getName() == "Charlieeeeee");
    // REQUIRE(member.getName() == "Charlie Dovey");
}

// Test case for all accessor functions in the librarian class.
TEST_CASE("Librarian get functionality", "[Librarian]"){
    // Librarian Alexa.
    REQUIRE(librarianAlexa.getStaffID() == 9999);
    REQUIRE(librarianAlexa.getSalary() == 100000);
    REQUIRE(librarianAlexa.getName() == "librarianAlexa");
    REQUIRE(librarianAlexa.getAddress() == "Amazon Ave");
    REQUIRE(librarianAlexa.getEmail() == "librarianalexahelpline@aws.com");
    // Librarian Siri.
    REQUIRE(librarianSiri.getStaffID() == 9998);
    REQUIRE(librarianSiri.getSalary() == 100000);
    REQUIRE(librarianSiri.getName() == "Siri");
    REQUIRE(librarianSiri.getAddress() == "Apple Ave");
    REQUIRE(librarianSiri.getEmail() == "sirihelpline@apple.com");
}

// Test case for all accessor functions in the librarian class.
TEST_CASE("Person set and get functionality", "[Person]"){
    person.setName("Charlie");
    person.setAddress("MDX Library");
    person.setEmail("cd908@live.mdx.ac.uk");
    REQUIRE(person.getName() == "Charlie");
    REQUIRE(person.getAddress() == "MDX Library");
    REQUIRE(person.getEmail() == "cd908@live.mdx.ac.uk");
    // Adding wrong test cases as an example.
    // Uncomment the below REQUIRE statements to see the test fail in the Catch2tests.exe
    // REQUIRE(newperson.getName() == "Sam");
    // REQUIRE(newperson.getAddress() == "MDX College Building");
    // REQUIRE(newperson.getEmail() == "cd9999@live.mdx.ac.uk");
}

// Test case for adding member objects to memory.
TEST_CASE("Librarian add member tests", "[Librarian]"){
    Member member(102, "Ahmed", "Roundabout road", "Ahmed@outlook.co.uk");
    Member newMember(103, "Ali", "Long Lane", "Ali@live.mdx.ac.uk");
    getMemberList().push_back(member);
    getMemberList().push_back(newMember);
    REQUIRE(getMemberList().size() == 2);
    librarianAlexa.printMemberDetails(102);
    librarianAlexa.printMemberDetails(103);
}