# Copyright 2023 < 323CA Dumitrascu Filip Teodor >

# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -Wshadow -std=c99

# define targets
TARGETS=my_octave

build:
	$(CC) $(CFLAGS) *.c -o my_octave

pack:
	zip -FSr 323CA_DumitrascuFilipTeodor_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean