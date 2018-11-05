#ifndef TARJAN_SCC
#define TARJAN_SCC
#include <vector> // std::vector
#include <algorithm> // std::min

class SCC {
    // Tarjan's algorithm to find strongly connected components
    // Vertices are integer
    // Input : a vector of vector of int as an adjcancy list
    // Output : strongly connected components of Input
    const std::vector<std::vector<int>>& adjlist;
    const int UNVISITED = -1;
    std::vector<int> stck, dfs_num, low_link;
    std::vector<bool> on_stck;
    int dfs_num_counter;
    int no_scc;

    void dfs(int v)
    {
        dfs_num[v] = low_link[v] = dfs_num_counter++;
        stck.push_back(v);
        on_stck[v] = true;

        for(int adj : adjlist[v]) {
            if(dfs_num[adj] == UNVISITED) {
                dfs(adj);
                low_link[v] = std::min(low_link[v], low_link[adj]);
            } else if(on_stck[adj] == true) {
                low_link[v] = std::min(low_link[v], dfs_num[adj]);
            }
        }

        if(low_link[v] == dfs_num[v]) 
        {
            // a strongly connected component found!
            no_scc++;
            while(true) {
                // u is a vertex in this strongly connected component
                int u = stck.back(); stck.pop_back(); on_stck[u] = false;
                if(u == v) break;
            }
        }
    }

public:
    SCC(const std::vector<std::vector<int>>& adjlist)
    : adjlist(adjlist)
    {
        dfs_num_counter = no_scc = 0;
        dfs_num.assign(adjlist.size(), UNVISITED);
        low_link.resize(adjlist.size());
        on_stck.assign(adjlist.size(), false);
    }

    void find_scc() {
        int min_vertex = 0, max_vertex = (int)adjlist.size() - 1;
        // 0 based vertices
        for(int i = min_vertex; i <= max_vertex; ++i) {
            if(dfs_num[i] == UNVISITED)
                dfs(i);
        }
    }

    int number_of_scc() {
        return no_scc;
    }
};

#endif