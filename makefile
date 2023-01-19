all: graph graph.o queue.o graph.c graph.h node.o edges.o main.o main.h

graph: graph.o queue.o node.o edges.o main.o
	gcc -Wall -g -o graph graph.o queue.o node.o edges.o main.o

node.o: node.c node.h
	gcc -Wall -g -c node.c

graph.o: graph.c graph.h
	gcc -Wall -g -c graph.c

queue.o: queue.c queue.h
	gcc -Wall -g -c queue.c

edges.o: edges.c edges.h
	gcc -Wall -g -c edges.c

main.o: main.c main.h
	gcc -Wall -g -c main.c

clean:
	rm graph *.o
