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
