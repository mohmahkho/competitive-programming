vector<vector<int>> adjlist;
vector<bool> vis;

void dfs(int u) {
  if(vis[u] == true) return;
  vis[u] = true;
  for(int adj : adjlist[u]) dfs(adj);
}
