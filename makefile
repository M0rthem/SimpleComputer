all: test

test: test.o
	gcc test.o -o test

test.o: console/test.c
	gcc -c console/test.c

clean:
	rm -rf *.o test
