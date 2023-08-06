CC=clang
FLAGS=-Os -Wall -Werror -pedantic

k: k.c Makefile
	$(CC) -o $@ k.c $(FLAGS)