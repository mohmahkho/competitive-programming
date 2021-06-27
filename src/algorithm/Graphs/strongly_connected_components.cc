struct strongly_connected_components {
  int n;
  const vector<vector<int>>& g;
  vector<int> num;
  vector<int> low;
  vector<int> vis;
  vector<int> cc; // cc[v] := 0-based connencted component number of vertex v

  int dfs_cnt = 0;
  int cc_cnt = 0;
  stack<int> stk;
  void dfs(int u) {
    num[u] = low[u] = ++dfs_cnt;
    vis[u] = 1;
    stk.push(u);

    for(int v : g[u]) {
      if(vis[v] == 0) {
        dfs(v);
        low[u] = min(low[u], low[v]);
      } else if(vis[v] == 1) {
        low[u] = min(low[u], num[v]);
      }
    }

    if(low[u] == num[u]) {
      // An SCC found
      while(true) {
        int v = stk.top(); stk.pop(); // v is in this CC 
        cc[v] = cc_cnt;
        vis[v] = 2;
        if(v == u) break;
      }
      cc_cnt += 1;
    }
  }

  strongly_connected_components(const vector<vector<int>>& g_)
    : n((int) g_.size())
    , g(g_)
    , num(n)
    , low(n)
    , vis(n)
    , cc(n)
  {
    for(int v = 0; v < n; ++v) {
      if(vis[v] == 0) {
        dfs(v);
      }
    }
  }

  vector<vector<int>> return_dag(bool reverse = false) {
    // Returns a dag with cc_cnt vertices
    // i -> j if i'th cc is connected to j'th cc
    // j -> i if reverse == true
    vector<pair<int, int>> edges;
    for(int u = 0; u < n; ++u) {
      for(int v : g[u]) {
        if(cc[u] != cc[v]) {
          edges.push_back({cc[u], cc[v]});
        }
      }
    }
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    vector<vector<int>> dag(cc_cnt);
    for(auto [u, v] : edges) {
      if(reverse) dag[v].push_back(u);
      else dag[u].push_back(v);
    }
    return dag;
  }
};
