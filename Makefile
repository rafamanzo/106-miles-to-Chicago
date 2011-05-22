CFLAGS = -ansi -Wall -pedantic -g
.PHONY: clean

chicago: main.c
	gcc main.c $(CFLAGS) -o Chicago

clean:
	rm Chicago
