CC = gcc
CFLAGS = -Wall -std=c99 -pedantic
MAIN = mytr
OBJS =  mytrFunctions.o mytr.o
all : $(MAIN)

$(MAIN) : $(OBJS) mytr.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

mytr.o : mytr.c mytrFunctions.o mytr.h
	$(CC) $(CFLAGS) -c mytr.c

mytrFunctions.o : mytrFunctions.c mytr.h
	$(CC) $(CFLAGS) -c mytrFunctions.c

clean :
	echo "clean"
	rm *.o $(MAIN) core

test :	$(MAIN)
	./mytr "abc" "123"
