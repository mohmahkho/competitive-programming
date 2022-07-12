auto get_connected_components(const vector<vector<int>>& g) {
  int n = (int) g.size();
  int ncc = 0; // number of connected components
  vector<int> cc(n, -1); // cc[u] = connected component id of u 
  vector<int> id(n); // id[u] = id of u in its cc
  vector<int> sz; // sz[t] = size of connected component t

  int id_cnt;
  auto dfs = [&] (auto self, int u) -> void {
    cc[u] = ncc;
    id[u] = id_cnt++;
    for(int v : g[u]) if(cc[v] == -1) {
      self(self, v);
    }
  };

  for(int u = 0; u < n; ++u) {
    if(cc[u] == -1) {
      id_cnt = 0;
      dfs(dfs, u);
      sz.push_back(id_cnt);
      ++ncc;
    }
  }
  return make_tuple(ncc, cc, id, sz);
}
