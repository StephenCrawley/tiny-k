CC=clang
FLAGS=-Os -Wall -Werror -Wunused-macros #-pedantic

k: k.c Makefile
	$(CC) -o $@ k.c $(FLAGS)