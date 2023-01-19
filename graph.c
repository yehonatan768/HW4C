#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "graph.h"
#include "node.h"
#include "queue.h"
#include "edges.h"
#include "main.h"


// build a graph from user input
void build_graph_cmd(pnode *head){
    int i;
    scanf("%d", &i);
    pnode current = findNode(i, *head);
    pedge prev = NULL;
    while(scanf("%d", &i)==1){
        pnode dest = findNode(i, *head);
        scanf("%d", &i);
        prev = createNewEdge(i,prev,dest);
    }
    current->edges = prev;
}

// insert a new node to the graph from user input
void insert_node_cmd(pnode *head){
    int i;
    scanf("%d", &i);
    pnode node = findNode(i, *head);
    if (*head == NULL){
        *head = newNode(i, NULL);
        node = *head;
    }
    else if(node != NULL){
        removeAllOutgoingEdges(node);
    }
    else{
        node = insertNode(i, head);
    }
    pedge prev = NULL;
    while(scanf("%d", &i)==1){
        pnode dest = findNode(i, *head);
        scanf("%d", &i);
        prev = createNewEdge(i,prev,dest);
    }
    node->edges = prev;
}

// delete a node in the graph from user input
void delete_node_cmd(pnode *head){
    int i=0;
    scanf("%d", &i);
    pnode remove = NULL;
    pnode check = *head;
    if (check->node_num == i){
        *head = check->next;
        remove = check;
    }
    else{
        while(check->next){
            if (check->next->node_num == i){
                remove = check->next;
                check->next = remove->next;
                break;
            }
            check= check->next;
        }
    }
    check = *head;
    while(check!=NULL){
        removeTo(i, check);
        check = check->next;
    }
    removeAllOutgoingEdges(remove);
    free(remove);
}

// print the current graph
void printGraph_cmd(pnode head){
    pedge p;
    while(head!=NULL){
        printf("node id: %d\n", head->node_num);
        p = head->edges;
        while(p!=NULL){
            printf("%d -> %d   w: %d\n", head->node_num, p->endpoint->node_num, p->weight);
            p= p->next;
        }
        head = head->next;
    }
}

// delete the entire graph
void deleteGraph_cmd(pnode* head){
    pnode node = *head;
    while(node!=NULL){
        removeAllOutgoingEdges(node);
        pnode delete = node;
        node = node->next;
        free(delete);
    }
}

// find the shortest path between two nodes in the graph from user input
void shortest_path_cmd(pnode head){
    int src=0,dest=0;
    while(scanf("%d", &src)==0);
    while(scanf("%d", &dest)==0);
    int src_id,dest_id;
    pnode p;
    pnode curr = head;
    int index=0;
    while (curr!=NULL){
        curr->seq = index;
        if (curr->node_num == src){
            p = curr;
            src_id = index;
        }
        if (curr->node_num == dest){
            dest_id = index;
        }
        index++;
        curr= curr->next;
    }
    int *arr=(int*)malloc(sizeof(int) * index);
    if(arr == NULL)
        exit(0);
    for (int i=0; i < index; i++){
        arr[i] = INT_MAX;
    }
    arr[src_id] = 0;
    shortestPath(arr, p);
    if (arr[dest_id] < INT_MAX){
        printf("Dijsktra shortest path: %d \n", arr[dest_id]);
    }
    else{
        printf("Dijsktra shortest path: -1 \n");
    }
    free(arr);
}

// finds the shortest path that visits all nodes in a graph using dynamic programming and prints the result to the user
void TSP_cmd(pnode head){
    int j;
    pnode q;
    scanf("%d", &j);
    int *cities=(int*)malloc(sizeof(int)*j);
    if(cities == NULL)
        exit(0);
    for(int i=0; i<j; i++){
        scanf("%d", &cities[i]);
    }
    q = head;
    int max = 0;
    while (q!=NULL){
        q->seq = max;
        max++;
        q= q->next;
    }
    int ans = INT_MAX;
    findShortestRoute(cities, 0, j - 1, max, &ans, head);
    if (ans != INT_MAX){
        printf("TSP shortest path: %d \n", ans);
    }
    else{
        printf("TSP shortest path: -1 \n");
    }
    free(cities);
}