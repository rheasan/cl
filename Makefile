CC = gcc
CARGS = -Wall -Wextra -ggdb
OBJECTS = main.o

build : $(OBJECTS)
	$(CC) $(CARGS) $(OBJECTS) -o main && make clean

main.o :
	$(CC) $(CARGS) -c ./src/main.c

clean:
	rm $(OBJECTS)

