CC=g++
CFLAGS=-Wall -pedantic -std=c++11 -O2
LIBS=`allegro-config --libs`

all:	program
program:	main.o arg.o dane.o grafika.o statystyka.o
	$(CC) -o program main.o arg.o dane.o grafika.o statystyka.o $(CFLAGS) $(LIBS)
arg.o: arg.cpp arg.hpp
	$(CC) -o arg.o -c arg.cpp $(CFLAGS)
dane.o: dane.cpp arg.hpp dane.hpp
	$(CC) -o dane.o -c dane.cpp $(CFLAGS)
grafika.o: grafika.cpp dane.hpp grafika.hpp
	$(CC) -o grafika.o -c grafika.cpp $(CFLAGS)
statystyka.o: statystyka.cpp statystyka.hpp dane.hpp grafika.hpp arg.hpp
	$(CC) -o statystyka.o -c statystyka.cpp $(CFLAGS)
main.o: main.cpp arg.hpp dane.hpp grafika.hpp statystyka.hpp
	$(CC) -o main.o -c main.cpp $(CFLAGS)
clean:
	rm -f *.o