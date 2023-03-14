CFLAGS=-std=c++17 
CC=g++

SFMLLIB= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
I=-I /opt/homebrew/Cellar/sfml/2.5.1_2/include/
L=-L /opt/homebrew/Cellar/sfml/2.5.1_2/lib

SRC=gameClass.o Main.o 

all: GameTest 

GameTest:$(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o GameTest $ $(I) $(L) $(SFMLLIB)

Main.o: main.cpp
	$(CC) $(STD) $(CFLAGS) -c main.cpp

gameClass.o: gameClass.cpp	
	$(CC) $(STD) $(CFLAGS) -c gameClass.cpp

clean:
	rm -f core *.o GameTest