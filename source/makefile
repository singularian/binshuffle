CC=gcc
CFLAGS=-Wall

all: shuffle

shuffle: shuffle.o 
	# $(CC) $(CFLAGS) -o shuffle shuffle.o rngList.o
	$(CC) $(CFLAGS) shuffle.o -o shuffle
clean:
	rm -f shuffle *.core *.o 
