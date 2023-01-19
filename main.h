// swaps the values of two integers passed as arguments
void swapIntegers(int* a, int* b);

// finds the shortest path from a given starting node to all other nodes 
// in the graph using a breadth-first search approach
void shortestPath(int *arr,pnode current);

// Recursive function that finds the shortest route that visits all cities 
// passed as an argument by using dynamic programming.
void findShortestRoute(int* cities,int start,int end,int size_of_nodes, int* ans, pnode head);