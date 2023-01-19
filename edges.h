
// creates a new edge with a specified weight, next edge, and destination node, and returns the new edge
pedge createNewEdge(int weight, pedge next, pnode dest);

// removes an edge to a node with specified data, starting from the input node 'current'
void removeTo(int data, pnode current);

// removes all outgoing edges from the input node 'current'
void removeAllOutgoingEdges(pnode current);
