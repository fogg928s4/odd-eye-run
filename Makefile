# Flags and compiler
CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror -Iinclude -std=c11
TARGET	:= bin/odd-eye-run

SRC_DIR	:= src
BIN_DIR	:= bin

# Execute
odd_eye_runner:
	$(CC) $(SRC_DIR)/main.c -o $(TARGET) $(CFLAGS)