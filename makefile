CC=gcc --std=c99 -g

all: test

test: test.o dynamicArray.o
	$(CC) dynamicArray.o -o test

dynamicArray.o: dynamicArray.c dynamicArray.h
	$(CC) -c dynamicArray.c

test.o: test.c
	$(CC) -c test.c

clean:
	rm -f *.o test
