auto is_bipartite(const vector<vector<int>>& g) -> bool { // multiedge is ok
  int n = (int) g.size();
  vector<int> color(n, -1);
  bool bipartite_check = true;
  auto dfs = [&] (const auto& self, int u, int c) -> void {
    color[u] = c;
    for(auto v : g[u]) {
      if(color[v] == -1) {
        self(self, v, 1 - c);
      } else if(color[v] == color[u]) {
        bipartite_check = false;
      }
    }
  };
  for(int u = 0; u < n; ++u) {
    if(color[u] == -1) {
      dfs(dfs, u, 0);
    }
  }
  return bipartite_check;
} // O(n)
