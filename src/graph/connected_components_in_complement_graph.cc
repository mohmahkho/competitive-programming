struct cc_complement {
  int n;
  set<pair<int, int>>& edges;
  set<int> notvis;
  vector<vector<int>> cc;

  void bfs(int s) {
    queue<int> q;
    q.push(s);
    notvis.erase(s);
    while(q.size()) {
      int u = q.front();
      q.pop();

      cc.back().push_back(u);

      for(auto it = notvis.begin(); it != notvis.end(); ) {
        if(!edges.count({u, *it}) && !edges.count({*it, u})) {
          q.push(*it);
          it = notvis.erase(it);
        } else ++it;
      }
    }
  }

  cc_complement(int n_, set<pair<int, int>>& e) : n(n_), edges(e) {
    for(int v = 1; v <= n; ++v) {
      notvis.insert(v);
    }
    for(int v = 1; v <= n; ++v) {
      if(notvis.count(v)) {
        cc.emplace_back();
        bfs(v);
      }
    }
  }
};
// O(mlogm), m = |edges|
