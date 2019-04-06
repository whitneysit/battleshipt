CFLAGS = -O -g
CC = g++ -std=c++11

main: board.o game.o ship.o main.cpp
	$(CC) $(CFLAGS) -o main game.o main.cpp board.o ship.o

game.o: Game.cpp Game.h Board.h
	$(CC) $(CFLAGS) -c Game.cpp

board.o: Board.cpp  Board.h Ship.h
	$(CC) $(CFLAGS) -c Board.cpp

ship.o: Ship.cpp Ship.h
	$(CC) $(CFLAGS) -c Ship.cpp 

clean:
	rm -f core *.o main
