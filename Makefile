CC = g++
CARGS = -Wall -Wextra -ggdb
OBJECTS = main.o cpplox.o

build : $(OBJECTS)
	$(CC) $(CARGS) $(OBJECTS) -o cpplox && make clean

main.o :
	$(CC) $(CARGS) -c ./src/main.cpp

cpplox.o :
	$(CC) $(CARGS) -c ./src/cpplox.cpp

clean:
	rm $(OBJECTS)

