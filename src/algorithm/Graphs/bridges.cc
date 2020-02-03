vector<pair<int, int>> bridges(vector<vector<int>>& g) {
  vector<int> num(g.size()), low(g.size()), vis(g.size());
  vector<pair<int, int>> br;
  function<void(int, int)> dfs = [&](int u, int p) {
    static int dn = 0;
    vis[u] = 1;
    num[u] = low[u] = dn++;
    for(int v : g[u]) {
      if(v != p) {
        if(vis[v]) {
          low[u] = min(low[u], num[v]);
        } else {
          dfs(v, u);
          if(low[v] > num[u]) {
            br.emplace_back(v, u);
          }
          low[u] = min(low[u], low[v]);
        }
      }
    }
  };
  dfs(0, -1);
  return br;
}
