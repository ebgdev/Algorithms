# Depth-First Search algorithm in C

# Author : Erfan BAGHCHEHDAN GHADIMI

# Email : ebgdev@proton.me
=================================================================

In this implementation, we have two functions dfs() and dfs_iterative() that perform 
Depth-First Search recursively and iteratively, respectively.

We first initialize an adjacency matrix graph of size MAX_SIZE x MAX_SIZE to represent
the graph. We also have a visited array of size MAX_SIZE to keep track of the visited 
nodes.

In the dfs() function, we start at the given start node and mark it as visited. We then 
recursively visit all adjacent unvisited nodes. The base case is when all adjacent nodes 
have been visited.

In the dfs_iterative() function, we use a stack to keep track of the nodes to be visited. 
We start by pushing the start node onto the stack and mark it as visited. We then pop nodes
 from the stack until the stack is empty. For each node popped, we push its unvisited 
 adjacent nodes onto the stack and mark them as visited.

Finally, we call these functions in the main() function and print the Depth-First Search traversal.
