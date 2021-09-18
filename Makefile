CC = cc
CFLAGS = -std=c11 -pedantic -Wall -Werror

build:
	mkdir -p bin
	$(CC) $(CFLAGS) src/config.c libs/tomlc99/toml.c -o bin/program

.PHONY: build