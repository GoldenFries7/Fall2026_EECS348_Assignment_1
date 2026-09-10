CC = gcc
CFLAGS = -Wall

all: prog

prog: main.o isOdd.o
	$(CC) $(CFLAGS) -o prog main.o isOdd.o

main.o: main.c isOdd.h
	$(CC) $(CFLAGS) -c main.c

isOdd.o: isOdd.c isOdd.h
	$(CC) $(CFLAGS) -c isOdd.c

clean:
	rm -f *.o prog