/*
If there is a tree in the problem and we are asked to find some subtrees of this tree 
with a particular property, then it's wise to think about rooting the tree.
for example rooting the tree at node 1.
by doing this, working with tree would be simpler but we need to be careful about double counting.
also this method makes it easier to use dynamic programming on these types of problems.
for example our dp state would be something like dp(u, k) and this means some value for
subtree rooted at u with some extra state like k.
*/
