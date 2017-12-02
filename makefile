CC=gcc --std=c99 -g

all: test

test: dynamicArray.o
	$(CC) dynamicArray.o -o test

dynamicArray.o: dynamicArray.c dynamicArray.h
	$(CC) -c dynamicArray.c

clean:
	rm -f *.o test
