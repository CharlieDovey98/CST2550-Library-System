#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "person.h"
#include "book.h"
#include "member.h"
#include "librarian.h"


// Test case for functions in the Book class.
TEST_CASE("Book functionality", "[Book]"){
    Book book(100, "The Test Book", "Testing", "Author");

    REQUIRE(book.getBookID() == "100");
    REQUIRE(book.getBookName() == "The Test Book");
    REQUIRE(book.getAuthorFirstName() == "Testing");
    REQUIRE(book.getAuthorLastName() == "Author");
}

// Test case for functions in the member class.
TEST_CASE("Member functionality", "[Member]"){
    Member member(101, "Charlie", "Deadend Rd", "cd908@live.mdx.ac.uk");

    REQUIRE(member.getMemberID() == "101");
    REQUIRE(member.getName() == "Charlie");
    // Adding a wrong test case as an example.
    // Uncomment the below REQUIRE to see the test fail in the Catch2tests.exe
    // REQUIRE(member.getName() == "Charlieeeeee");
    REQUIRE(member.getAddress() == "Deadend Rd");
    REQUIRE(member.getEmail() == "cd908@live.mdx.ac.uk");
}