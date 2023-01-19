#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

//typedef for struct of a graph edge, containing a weight, an endpoint, and a pointer to the next edge
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

//typedef for struct of a graph node, containing an id, a list of edges, and a pointer to the next node
typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int seq;
} node, *pnode;

// build a graph from user input
void build_graph_cmd(pnode *head); 

// insert a new node to the graph from user input
void insert_node_cmd(pnode *head);

// delete a node in the graph from user input
void delete_node_cmd(pnode *head);

// print the current graph
void printGraph_cmd(pnode head); //for self debug

// delete the entire graph
void deleteGraph_cmd(pnode* head);

// find the shortest path between two nodes in the graph from user input
void shortest_path_cmd(pnode head);

// finds the shortest path that visits all nodes in a graph using dynamic programming and prints the result to the user
void TSP_cmd(pnode head);



#endif
