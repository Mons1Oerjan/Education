# To run, enter make or make all

all: rtp

rtp: prog2.o
	gcc -o rtp prog2.o

prog2.o: prog2.c
	gcc -c prog2.c

clean:
	rm -f *.o rtp
