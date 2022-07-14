vector<vector<pair<int, int>>> adj; // our graphs adj list
deque<int> dq; // double ended queue
vector<int> dist(MAXN, INF); // distance array
int start_vertex = 1; // start vertex

dist[start_vertex] = 0;
dq.push_front(start_vertex);

while(!dq.empty())
{
    int u = dq.front();
    dq.pop_front();

    for(auto edge : adj[u]) {
        int w = edge.first,
            v = edge.second;
        if(dist[u] + w >= dist[v]) continue;

        dist[v] = dist[u] + w;
        if(w) dq.push_back(v);
        else dq.push_front(v);
    }
}

/*
Dial's algorithm
We can extend this even further if we allow the weights of the edges to be even bigger.
If every edge in the graph has a weight ≤k, than the distances of vertices in the queue will differ by at most k 
from the distance of v to the source. So we can keep k+1 buckets for the vertices in the queue, and whenever the bucket 
corresponding to the smallest distance gets empty, we make a cyclic shift to get the bucket with the next higher distance.
This extension is called Dial's algorithm.
*/
