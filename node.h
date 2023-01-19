// creates a new node in the graph with a given id and a pointer to the next node in the list
pnode newNode(int k, pnode next);

// creates a list of k nodes with sequential ids starting from 0
pnode generateNodes(int k);

// insert a new node with a given id in the list in the correct position
pnode insertNode(int data, pnode *head);

// find a node with a given id in the list and return a pointer to it.
pnode findNode(int data, pnode head);
