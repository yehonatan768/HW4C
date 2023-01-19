#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "queue.h"
#include "edges.h"
#include "main.h"

// swaps the values of two integers passed as arguments
void swapIntegers(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// finds the shortest path from a given starting node to all other nodes 
// in the graph using a breadth-first search approach
void shortestPath(int *arr,pnode current){
    queuenode* q = newQueue(current, 0);
    while (!isEmpty(&q)){
        current = dequeue(&q);
        pedge curr_edge = current->edges;
        while(curr_edge!=NULL){
            if (arr[current->seq] + curr_edge->weight < arr[curr_edge->endpoint->seq]){
                arr[curr_edge->endpoint->seq] = arr[current->seq] + curr_edge->weight;
                enqueue(&q, curr_edge->endpoint, arr[curr_edge->endpoint->seq]);
            }
            curr_edge= curr_edge->next;
        }
    }
}

// Recursive function that finds the shortest route that visits all cities 
// passed as an argument by using dynamic programming.
void findShortestRoute(int* cities, int start, int end, int size_of_nodes, int* ans, pnode head){
    pnode q;
    if (start == end){
        int check =0;
        int *p=(int*)malloc(sizeof(int) * size_of_nodes);
        if(p == NULL)
            exit(0);
        for (int i=0;i<size_of_nodes;i++){
            p[i] =  INT_MAX;
        }
        q = findNode(cities[0], head);
        p[q->seq] = 0;
        for (int i=1;i<=end;i++){
            shortestPath(p, q);
            if (p[findNode(cities[i], head)->seq] == INT_MAX){
                free (p);
                return;
            }
            q = findNode(cities[i], head);
            check = check + p[q->seq];
            for (int j=0;j<size_of_nodes;j++){
                p[j] =  INT_MAX;
            }
            p[q->seq] = 0;
        }
        free (p);
        if (check < *ans && check !=0){
            *ans = check;
        }
        return;
    }
    for (int k=start;k<=end;k++){
        swapIntegers(cities + k, cities + start);
        findShortestRoute(cities, start + 1, end, size_of_nodes, ans, head);
        swapIntegers(cities + k, cities + start);
    }
}

int main(){
    char s;
    pnode head = NULL;
    int done = 0, k;
    while(done!=EOF){
        done = scanf("%c", &s);
        if (s == 'A') {
            deleteGraph_cmd(&head);
            scanf("%d", &k);
            head = generateNodes(k);
        } else if (s == 'B') {
            insert_node_cmd(&head);
        } else if (s == 'D') {
            delete_node_cmd(&head);
        } else if (s == 'n') {
            build_graph_cmd(&head);
        } else if (s == 'p') {
            printGraph_cmd(head);
        } else if (s == 'S') {
            shortest_path_cmd(head);
        } else if (s == 'T') {
            TSP_cmd(head);
        }
    }
    deleteGraph_cmd(&head);
    return 0;
}
