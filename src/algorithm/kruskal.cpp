#include <algorithm> // std::sort
#include "../ds/Graph.hpp"
#include "../ds/UnionFind.hpp"

// @return minimum spanning tree's weight
weight_t kruskal(int number_of_vertices, wedgelist& wel)
{
    std::sort(wel.begin(), wel.end());
    UnionFind disjoint_set(number_of_vertices); // 0 based
    
    int number_of_edges = number_of_vertices - 1;
    weight_t mst = 0;
    
    for(wedge& we : wel) {
        if(number_of_edges <= 0) break;

        vertex_t u = we.second.first, v = we.second.second;
        if(disjoint_set.in_same_set(u, v)) continue; // loop : NOT OK

        // no loop : OK
        disjoint_set.union_set(u, v);
        mst += we.first;
        number_of_edges--;
    }

    return mst;
}

int main()
{
}