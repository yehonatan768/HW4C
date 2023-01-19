#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

// creates a new node in the queue with a given data and priority value
queuenode* newQueue(pnode data, int value){
    queuenode* p = (queuenode*)malloc(sizeof(queuenode));
    if(p == NULL)
        exit(0);
    p->nodedata = data;
    p->priority = value;
    p->next = NULL;
    return p;
}

// insert a new node with a given data and priority in the queue in the correct position
void enqueue(queuenode** head, pnode d, int p){
    queuenode* start = (*head);
    queuenode* temp = newQueue(d, p);
    if (isEmpty(head)){
        (*head) = temp;
        return;
    }

    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    }
    else {

        while (start->next != NULL &&
               start->next->priority < p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

// remove the node with the highest priority from the queue and return its data
pnode dequeue(queuenode** head){
    pnode temp = (*head)->nodedata;
    queuenode* temptofree = *head;
    (*head) = (*head)->next;
    free(temptofree);
    return temp;
}

// check if the queue is empty and return true or false.
int isEmpty(queuenode** head){
    return (*head) == NULL;
}
