#ifndef _MK_GRAPH_
#define _MK_GRAPH_

#include <vector> // std::vector
#include <utility> // std::pair

// All containers can be used in directed or undirected graphs
typedef int vertex_t; // change when needed
typedef int weight_t; // change when needed

typedef std::pair<weight_t, vertex_t> wvpair;
typedef std::pair<vertex_t, vertex_t> edge; 
typedef std::pair<weight_t, std::pair<vertex_t, vertex_t>> wedge; 

typedef std::vector<std::vector<long>> adjmatrix; // adjmatrix mat(n, vector<long>(n));
typedef std::vector<std::vector<vertex_t>> adjlist;
typedef std::vector<std::vector<wvpair>> wadjlist;
typedef std::vector<edge> edgelist;
typedef std::vector<wedge> wedgelist;

#endif
