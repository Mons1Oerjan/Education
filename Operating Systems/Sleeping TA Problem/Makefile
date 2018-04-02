# To run, enter make or make all

all: testsleepingta

testsleepingta: test.o sleepingta.o
	gcc -lpthread -o sleepingta test.o sleepingta.o

sleepingta.o: sleepingta.c sleepingta.h
	gcc -c sleepingta.c

test.o: test.c sleepingta.h
	gcc -lpthread -c test.c

clean:
	rm -f *.o sleepingta
