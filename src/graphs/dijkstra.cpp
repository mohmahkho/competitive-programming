// Compile with C++17 Standard
pair<vector<long long>, vector<int>> dijdad(int s) {
  vector<long long> dist(N, INF);
  vector<int> dad(N, -1);
  priority_queue<pair<long long, int>,
                 vector<pair<long long, int>>, 
                 greater<pair<long long, int>>> pq;
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
