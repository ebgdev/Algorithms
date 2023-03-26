# Breadth-First Search

# Author : Erfan Baghchehdan Ghadimi

# Email : ebgdev@proton.me

=========================================================

# Breadth-First Search
Here, we are using an adjacency matrix to represent the graph. We initialize an array visited to mark which nodes have been visited, and a queue to store nodes that need to be processed. The enqueue and dequeue functions are used to add nodes to the queue and remove nodes from it, respectively.

The bfs function performs the actual Breadth-First Search. We start by marking the starting node as visited and enqueueing it. Then we repeatedly dequeue a node from the queue, print its value, and enqueue all its unvisited neighbors. We continue this process until the queue is empty.

In the main function, we take the input for the graph and the starting node, and then call bfs to perform the Breadth-First Search.