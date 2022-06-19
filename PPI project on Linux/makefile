#############################
# Author: Yumeng Chen, Suran Wang, Luchi Xiao
# Last edit time: 2022.6.18
# # Functions: Complie the c program file and pack up as static library
#############################

CC = gcc
PATH_LIB = ./lib
PATH_SRC = ./src
PATH_BIN = ./bin
PATH_HEAD = ./include
NAME_LIB = PPI
all:$(PATH_SRC)/PPI.c
	$(CC) -c -o static/PPI.o src/PPI.c
	ar rsc $(PATH_LIB)/lib$(NAME_LIB).a static/PPI.o
.PHONY: install
install:
	$(CC) -static -o $(PATH_BIN)/main.static $(PATH_SRC)/main.c -L$(PATH_LIB) -l$(NAME_LIB) -I$(PATH_HEAD) 
PHONY: clean
clean:
	rm -rf *PPI.o
