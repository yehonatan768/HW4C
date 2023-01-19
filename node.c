#include "stdio.h"
#include "graph.h"
#include "stdlib.h"


// creates a new node in the graph with a given id and a pointer to the next node in the list
pnode newNode(int k, pnode next){
    pnode p = (pnode) malloc(sizeof(node));
    if(p==NULL)
        exit(0);
    p->node_num = k;
    p->next = next;
    p->edges = NULL;
    return p;
}

// creates a list of k nodes with sequential ids starting from 0
pnode generateNodes(int k){
    pnode head = NULL;
    for (int i=0; i<k; i++){
        head = newNode(i,head);
    }
    return head;
}

// insert a new node with a given id in the list in the correct position
pnode insertNode(int data, pnode *head){
    pnode *p = head;
    pnode new = newNode(data,NULL);
    while((*p) != NULL){
        if((*p)->node_num > data){
            new->next = (*p);
            *p = new;
            return new;
        }
        p = &((*p)->next);
    }
    *p = new;
    return new;
}

// find a node with a given id in the list and return a pointer to it.
pnode findNode(int data, pnode head){
    while (head){
        if (head->node_num == data){
            return head;
        }
        head = head->next;
    }
    return NULL;
}