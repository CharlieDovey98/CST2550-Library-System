
# Flags.
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic
# Source directories.
SRCDIRECTORY = src
OBJDIRECTORY = object

# Targets.
all: LibraryManagementSystem Catch2tests

# Operations.
Catch2tests: $(SRCDIRECTORY)/test.cpp $(OBJDIRECTORY)/person.o $(OBJDIRECTORY)/book.o $(OBJDIRECTORY)/member.o $(OBJDIRECTORY)/librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^

LibraryManagementSystem: $(OBJDIRECTORY)/main.o $(OBJDIRECTORY)/person.o $(OBJDIRECTORY)/book.o $(OBJDIRECTORY)/member.o $(OBJDIRECTORY)/librarian.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIRECTORY)/main.o: $(SRCDIRECTORY)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIRECTORY)/person.o: $(SRCDIRECTORY)/person.cpp $(SRCDIRECTORY)/person.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIRECTORY)/book.o: $(SRCDIRECTORY)/book.cpp $(SRCDIRECTORY)/book.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIRECTORY)/member.o: $(SRCDIRECTORY)/member.cpp $(SRCDIRECTORY)/member.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIRECTORY)/librarian.o: $(SRCDIRECTORY)/librarian.cpp $(SRCDIRECTORY)/librarian.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target to clean/ remove files.
.PHONY: clean
clean:
	$(RM) $(OBJDIRECTORY)/*.o LibraryManagementSystem Catch2tests