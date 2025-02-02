CC = g++
CARGS = -Wall -Wextra -ggdb
OBJECTS = main.o cpplox.o tokenizer.o

build : $(OBJECTS)
	$(CC) $(CARGS) $(OBJECTS) -o cpplox && make clean

main.o : ./src/main.cpp ./src/main.hpp
	$(CC) $(CARGS) -c ./src/main.cpp

cpplox.o : ./src/cpplox.cpp ./src/cpplox.hpp
	$(CC) $(CARGS) -c ./src/cpplox.cpp

tokenizer.o : ./src/tokenizer.cpp ./src/tokenizer.hpp ./src/token.hpp
	$(CC) $(CARGS) -c ./src/tokenizer.cpp

clean:
	rm $(OBJECTS)
