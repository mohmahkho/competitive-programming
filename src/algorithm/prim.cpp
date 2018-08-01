#include <queue> // std::priority_queue
#include <vector> // std::vector<bool>
#include <functional> // std::greater
#include "../ds/Graph.hpp" // weight_t, wadjlist, wvpair

// @return minimum spanning tree's weight
weight_t prim(wadjlist& wal)
{
    std::vector<bool> taken;
    taken.assign(wal.size(), false);
    std::priority_queue<wvpair, vector<wvpair>, std::greater<wvpair>> pq;

    taken[0] = true;
    for(wvpair& adj : wal[0]) pq.push(adj);

    weight_t mst = 0;
    while(!pq.empty())
    {
        wvpair wvp = pq.top();
        pq.pop();

        if(taken[wvp.second] == true) continue;
        taken[wvp.second] = true;
        mst += wvp.first;
        for(wvpair& adj : wal[wvp.second]) if(!taken[adj.second]) pq.push(adj);
    }
    
    return mst;
}

int main()
{
}