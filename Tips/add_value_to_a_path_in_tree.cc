/*
Suppose we want to add +x to each node in the simple path from u to v in a tree (including u and v).
First we need to make tree rooted (possibly at 1).
Then we should add +x to each of u and v and -2x to the lca(u, v).
After that the answer (value of each node) will be computed by a single dfs.
ans[v] = sum of subtree of v (excluding itself)
*/
