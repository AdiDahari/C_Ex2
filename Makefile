CC = gcc
AR = ar
FLAGS = -Wall -g
BANKOBJS = myBank.o
MAINOBJS = main.o

all: main

main: libmyBank.a $(MAINOBJS)
	$(CC) $(FLAGS) -o main $(MAINOBJS) $(BANKOBJS)
myBank: libmyBank.a
libmyBank.a: $(BANKOBJS)
	$(AR) -rcs libmyBank.a $(BANKOBJS)
main.o: main.c
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so main myBank