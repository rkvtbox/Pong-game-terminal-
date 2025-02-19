CC = gcc
CC_FLAGS = -std=c11 -Wall -Wextra -Werror
BIN = ../build/pong


all: main.c 
	
	$(CC) -lncurses main.c -o $(BIN) 


rebuild: clear rebuild


clear:
	rm -f ../my_libs/*.o $(BIN) a.out