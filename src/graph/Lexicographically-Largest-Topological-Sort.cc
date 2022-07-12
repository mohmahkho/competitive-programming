    priority_queue<int> pq;
    for(int x : h) if(indeg[x] == 0) pq.push(x);

    vector<int> ans;
    while(!pq.empty()) {
      int u = pq.top();
      pq.pop();
      ans.push_back(u);
      for(int v : g[u]) {
        indeg[v]--;
        if(indeg[v] == 0) pq.push(v);
      }
    }
