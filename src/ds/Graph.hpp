#ifndef _MK_GRAPH_
#define _MK_GRAPH_

#include <vector> // std::vector
#include <utility> // std::pair

using std::vector;
using std::pair;

// All containers can be used in directed or undirected graphs
typedef int vertex_t;
typedef int weight_t;

typedef pair<weight_t, vertex_t> wvpair;
typedef pair<vertex_t, vertex_t> edge; 
typedef pair<weight_t, pair<vertex_t, vertex_t>> wedge; 

typedef vector<vector<int>> adjmatrix;
typedef vector<vector<vertex_t>> adjlist;
typedef vector<wvpair> wadjlist;
typedef vector<edge> edgelist;
typedef vector<wedge> wedgelist;

#endif