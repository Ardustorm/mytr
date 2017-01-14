CC = gcc
CFLAGS = -Wall -std=c99 -pedantic
MAIN = mytr
OBJS = mytr.o 
all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


clean :
	echo "clean"
	rm *.o $(MAIN) core
