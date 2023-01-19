#include "graph.h" 
#include "stdlib.h"
#include "edges.h"

// creates a new edge with a specified weight, next edge, and destination node, and returns the new edge
pedge createNewEdge(int weight, pedge next, pnode dest){
    pedge p = (pedge) malloc(sizeof(edge));
    p->endpoint = dest;
    p->next = next;
    p->weight = weight;
    return p;
}

//removes an edge to a node with specified data, starting from the input node 'current'
void removeTo(int data, pnode current){
    pedge prev = NULL;
    pedge check_edge = current->edges;
    while(check_edge != NULL){
        if (check_edge->endpoint->node_num == data){
            if(prev == NULL){
                current->edges = check_edge->next;
            }else{
                prev->next = check_edge->next;
            }
            free(check_edge);
            return;
        }
        prev = check_edge;
        check_edge = check_edge->next;
    }
}

// removes all outgoing edges from the input node 'current'
void removeAllOutgoingEdges(pnode current){
    pedge next = current->edges;
    while(next){
        pedge prev = next;
        next = next->next;
        free(prev);
    }
}
