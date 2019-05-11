/*
Suppose we have a sequence of objects and we want to find a permutation of them
which maximizes some property. lets call this permutation p[1], p[2], ..., p[n].
we recognize if we there are indecies like i and j such that if we swap p[i] and
p[j] then the answer would be better (increased in case of maximizing and decreased
in case of minimizing) we can maximize the propery by finding all i and js and swapping
them. (i.e. sorting in increasing order. if we have a permutation like p[1], ..., p[n]
and we find indecies like i and j (i < j) where p[i] > p[j] if we swap these two 
we will reach a better state. in this case decreasing number of inversions.)
*/
