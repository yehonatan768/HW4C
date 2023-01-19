#include "graph.h"

// typedef for struct of a edge, containing a weight, 
// a pointer to the endpoint, and a pointer to the next edge in the list.
typedef struct queueNode {
	pnode nodedata;
	int priority;
	struct queueNode* next;
} queuenode;

// creates a new node in the queue with a given data and priority value
queuenode* newQueue(pnode data, int value);

// insert a new node with a given data and priority in the queue in the correct position
void enqueue(queuenode** head, pnode d, int p);

// remove the node with the highest priority from the queue and return its data
pnode dequeue(queuenode** head);

// check if the queue is empty and return true or false.
int isEmpty(queuenode** head);