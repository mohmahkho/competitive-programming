#include <algorithm> // std::sort
#include <../Graph.hpp> // Weight, WEdgeList, WEdge, Vertex
#include <../UnionFind.hpp> // UnionFind

// @return minimum spanning tree's weight
Weight kruskal(int number_of_vertices, WEdgeList& weighted_edge_list)
{
    std::sort(weighted_edge_list.begin(), weighted_edge_list.end());
    UnionFind disjoint_set(number_of_vertices); // 0 based
    
    int number_of_edges = number_of_vertices - 1;
    Weight mst = 0;
    
    for(WEdge& weighted_edge : weighted_edge_list) {
        if(number_of_edges <= 0) break;

        Vertex u = weighted_edge.second.first, v = weighted_edge.second.second;
        if(disjoint_set.in_same_set(u, v)) continue; // loop : NOT OK

        // no loop : OK
        disjoint_set.union_set(u, v);
        mst += weighted_edge.first;
        number_of_edges--;
    }

    return mst;
}
