CC=g++
CFLAGS=-c -Wall -std=c++11 -g

All : DBGen

DBGen : main.o io.o members.o
	$(CC) main.o io.o members.o -o a.out
	
main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp
	

	
io.o : io.cpp
	$(CC) $(CFLAGS) io.cpp
	
members.o : members.cpp
	$(CC) $(CFLAGS) members.cpp
	
clean : 
	rm -rf *.o a.out
