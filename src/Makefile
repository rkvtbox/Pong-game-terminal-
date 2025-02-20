CC = gcc
CC_FLAGS = -std=c11 -Wall -Wextra -Werror
LIBS = -lncurses
BIN = ../build/pong


all: main.c ../my_libs/display.c ../my_libs/pong_logics.c
	$(CC) $(CC_FLAGS) -c ../my_libs/display.c -o ../build/display.o
	$(CC) $(CC_FLAGS) -c ../my_libs/pong_logics.c -o ../build/pong_logics.o
	$(CC) $(CC_FLAGS) -c main.c -o ../build/main.o
	$(CC) ../build/main.o ../build/display.o ../build/pong_logics.o -lncurses -o ../build/pong


rebuild: clear rebuild


clean:
	rm -f ../build/*.o $(BIN)