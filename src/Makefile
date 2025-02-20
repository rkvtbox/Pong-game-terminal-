CC = gcc
CC_FLAGS = -std=c11 -Wall -Wextra -Werror
LIBS = -lncurses
BIN = ../build/pong


all: main.c ../my_libs/display.c
	$(CC) $(CC_FLAGS) -c ../my_libs/display.c -o ../build/display.o
	$(CC) $(CC_FLAGS) -c main.c -o ../build/main.o
	$(CC) ../build/main.o ../build/display.o -lncurses -o ../build/pong
	rm -f ../build/*.o

rebuild: clear rebuild


clean:
	rm -f ../build/*.o $(BIN)