int diameter(vector<vector<int>>& tree) {
  vector<int> lev(tree.size());
  function<void(int, int, int)> dfs = [&](int u, int p, int l) {
    lev[u] = l;
    for(int v : tree[u]) {
      if(v != p) {
        dfs(v, u, l + 1);
      }
    }
  };
  dfs(0, -1, 0);
  dfs(max_element(lev.begin(), lev.end()) - lev.begin(), -1, 0);
  return *max_element(lev.begin(), lev.end());
}
