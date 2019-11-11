/*
Suppose you want to check all the cycles in the graph.
There is an O(N(N + M)) approach to that.
You can start BFS on every node and you can check all the cycles that the starting node is part of.
If there is a back edge in BFS you check if this back edge goes back to the starting node, and if so, you have found 
a cycle that starting node is part of. With this algorithm you can find ALL cycles of a graph (either directed or undirected).
*/
