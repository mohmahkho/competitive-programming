struct dsu {
  vector<int> p;
  dsu(int n) {
    p.assign(n, -1);
  }
  int find(int v) {
    return p[v] < 0 ? v : p[v] = find(p[v]);
  }
  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
      if(p[u] < p[v]) swap(u, v);
      p[v] += p[u];
      p[u] = v;
      return true;
    }
    return false;
  }
};
