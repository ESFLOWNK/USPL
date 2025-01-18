
CC = gcc
FLAGS = -W

SRC_DIR = ./src
BIN_DIR = ./bin

CFILES = $(wildcard ./src/*.c)

EXE_NAME = USPL

$(BIN_DIR)/$(EXE_NAME): $(CFILES)
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm ./bin/*