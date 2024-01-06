
system: main.o person.o book.o member.o librarian.o
	g++ main.o person.o book.o member.o librarian.o -o system

main.o: main.cpp
	g++ -c main.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

member.o: member.cpp member.h
	g++ -c member.cpp

librarian.o: librarian.cpp librarian.h
	g++ -c librarian.cpp

clean:
	rm *.o system