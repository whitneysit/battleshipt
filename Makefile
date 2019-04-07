CFLAGS = -O -g -Wall
CC = g++ -std=c++11

main: main.o Ship.o Board.o Game.o 
	$(CC) $(CFLAGS) Ship.o Board.o Game.o main.o -o main

main.o: main.cpp Position.h Ship.h Board.h Game.h 
	$(CC) $(CFLAGS) -c main.cpp

Ship.o: Ship.h
	$(CC) $(CFLAGS) -c Ship.cpp 

Board.o:  Board.h 
	$(CC) $(CFLAGS) -c Board.cpp 

Game.o: Game.h
	$(CC) $(CFLAGS) -c Game.cpp

clean:
	rm -f core *.o main
