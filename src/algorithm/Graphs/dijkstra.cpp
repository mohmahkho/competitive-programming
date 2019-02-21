using PII = pair<int, int>;
int constexpr MAXN = 300009, INF = numeric_limits<int>::max() / 8;
vector<vector<PII>> adjlist;
vector<int> dist(MAXN, INF), dad(MAXN, -1);

void dijkstra(int s)
{
    dist[s] = 0;
    dad[s] = s;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({dist[s], s});

    while(!pq.empty())
    {
        PII here = pq.top();
        pq.pop();
        int d = here.first, v = here.second;
        if(d > dist[v]) continue;
        
        for(PII& adj : adjlist[v]) {
            int w = adj.first, u = adj.second;
            if(w + d < dist[u]) {
                dist[u] = w + d;
                dad[u] = v;
                pq.push({dist[u], u});
            }
        }
    }
}
