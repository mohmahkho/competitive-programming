#ifndef _MK_UNION_FIND_
#define _MK_UNION_FIND_

#include <vector> // std::vector

typedef class UnionFind
{ // Heuristics : "union by rank" and "path compression"
private:
    std::vector<int> parent, rank;
public:
    UnionFind(int N) {
        // N represents nodes where nodes start from 0 to N-1
        parent.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++) parent[i] = i;
    }

    int find_set(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find_set(parent[i]); // path compression
    }

    bool in_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_set(int i, int j) {
        if(in_same_set(i, j) == true) return;
        int i_set = find_set(i), j_set = find_set(j);

        // union by rank
        if(rank[i_set] < rank[j_set]) parent[j_set] = i_set;
        else {
            parent[i_set] = j_set;
            if(rank[i_set] == rank[j_set]) rank[j_set]++;
        }
    }
} DisjointSet;

#endif
