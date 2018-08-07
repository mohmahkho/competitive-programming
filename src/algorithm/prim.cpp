#include <vector> // std::vector<bool>
#include "../ds/Graph.hpp" // Weight, WAdjList, WV, MinWVPQ

// @return minimum spanning tree's weight
Weight prim(WAdjList& weighted_adjlist)
{
    std::vector<bool> taken;
    taken.assign(weighted_adjlist.size(), false);
    MinWVPQ pq;

    taken[0] = true;
    for(WV& adj_wv : weighted_adjlist[0]) pq.push(adj_wv);

    Weight mst = 0;
    while(!pq.empty())
    {
        WV top_wv = pq.top();
        pq.pop();

        if(taken[top_wv.second] == true) continue;

        taken[top_wv.second] = true;
        mst += top_wv.first;
        
        for(WV& adj_wv : weighted_adjlist[top_wv.second])
            if(!taken[adj_wv.second])
                pq.push(adj_wv);
    }
    
    return mst;
}
