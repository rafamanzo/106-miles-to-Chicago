CFLAGS = -ansi -Wall -pedantic -g
.PHONY: clean

chicago: main.o chicago.o graph.o digraph.o queue.o
	gcc main.o chicago.o graph.o digraph.o queue.o -o Chicago

main.o: main.c chicago.h ed/vertex.h ed/digraph.h ed/graph.h
	gcc -c main.c $(CFLAGS)

graph.o: ed/graph.c ed/graph.h ed/vertex.h ed/digraph.h
	gcc -c ed/graph.c $(CFLAGS)

digraph.o: ed/digraph.c ed/digraph.h ed/digraph_globals.h ed/vertex.h ed/queue/queue.h
	gcc -c ed/digraph.c $(CFLAGS)

queue.o: ed/queue/queue.c ed/queue/queue.h ed/vertex.h ed/digraph.h ed/digraph_globals.h
	gcc -c ed/queue/queue.c $(CFLAGS)

chicago.o: chicago.c chicago.h ed/vertex.h ed/digraph.h ed/digraph_globals.h ed/graph.h
	gcc -c chicago.c $(CFLAGS)

clean:
	rm *.o
	rm Chicago
