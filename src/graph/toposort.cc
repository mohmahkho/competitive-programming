vector<int> toposort(const vector<vector<int>>& dag) {
  int n = (int) dag.size();
  vector<int> indeg(n);
  for(int u = 0; u < n; ++u) for(int v : dag[u]) {
    indeg[v] += 1;
  }
  vector<int> ord(n);
  int p = 0;
  for(int u = 0; u < n; ++u) if(!indeg[u]) {
    ord[p++] = u;
  }
  for(int i = 0; i < n; ++i) for(int v : dag[ord[i]]) {
    indeg[v] -= 1;
    if(!indeg[v]) {
      ord[p++] = v;
    }
  }
  return ord;
}
