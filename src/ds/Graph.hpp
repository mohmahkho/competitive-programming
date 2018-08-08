#ifndef _MK_GRAPH_
#define _MK_GRAPH_

#include <vector> // std::vector
#include <utility> // std::pair
#include <queue> // std::priority_queue
#include <functional> // std::greater
#include <limits> // std::numeric_limits

// All containers can be used in directed or undirected graphs
typedef int Vertex; // change when needed
typedef long Weight; // change when needed

typedef std::pair<Weight, Vertex> WV;
typedef std::pair<Vertex, Vertex> Edge; 
typedef std::pair<Weight, Edge> WEdge;

typedef std::vector<std::vector<long>> AdjMatrix;
// AdjMatrix adjmat(n, vector<long>(n));
typedef std::vector<std::vector<Vertex>> AdjList;
typedef std::vector<std::vector<WV>> WAdjList;
typedef std::vector<Edge> EdgeList;
typedef std::vector<WEdge> WEdgeList;

typedef std::priority_queue<WV>
MaxWVPQ; // Maximum has a higher priority
typedef std::priority_queue<WV, std::vector<WV>, std::greater<WV>>
MinWVPQ; // Minimum has a higher priority

const Weight INF_WEIGHT = std::numeric_limits<Weight>::max() / 3; // !overflow
const Vertex INF_VERTEX = std::numeric_limits<Vertex>::max(); // no ocerflow

#endif
