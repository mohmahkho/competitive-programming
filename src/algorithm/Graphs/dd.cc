template<typename W, W inf = numeric_limits<W>::max() / 2>
pair<vector<W>, vector<int>> dd(const vector<vector<pair<W, int>>>& g, int s) {
  vector<W> dist(g.size(), inf);
  vector<int> dad(g.size(), -1);
  priority_queue<pair<W, int>, vector<pair<W, int>>, greater<pair<W, int>>> pq;
  dist[s] = 0;
  pq.push({dist[s], s});
  while(pq.size()) {
    auto [d, u] = pq.top();
    pq.pop();
    if(dist[u] < d) {
      continue;
    }
    for(auto [w, v] : g[u]) {
      if(d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({dist[v], v});
        dad[v] = u;
      }
    }
  }
  return {dist, dad};
}
