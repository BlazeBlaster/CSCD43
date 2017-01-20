CC = gcc
all: library.o create_random_file get_histogram
library.o: library.c library.h
	$(CC) -o library.o -c library.c
 
create_random_file: create_random_file.c library.o
	$(CC) -o $@ $< library.o
 
get_histogram: get_histogram.c library.o
	$(CC) -o $@ $< library.o