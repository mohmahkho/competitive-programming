template<typename W>
struct WTree {
  // 0-based
  const int N, LgN;
  vector<vector<pair<W, int>>> g;
  vector<vector<int>> par;
  vector<vector<W>> val;
  vector<int> lev;
  const W id;
  function<W(W, W)> op;
  WTree(int n, vector<pair<W, pair<int, int>>> edges, function<W(W, W)> op_, W id_) :
    N(n), LgN(32 - __builtin_clz(n)), op(op_), id(id_) {
    g.assign(N, {});
    par.assign(LgN, vector<int>(N, 0));
    val.assign(LgN, vector<W>(N, id));
    lev.assign(N, 0);
    for(auto [w, e] : edges) {
      auto [u, v] = e;
      g[u].emplace_back(w, v);
      g[v].emplace_back(w, u);
    }
    function<void(int, int)> dfs = [&] (int u, int p) {
      par[0][u] = p;
      lev[u] = lev[p] + 1;
      for(auto [w, v] : g[u]) {
        if(v != p) {
          val[0][v] = w;
          dfs(v, u);
        }
      }
    };
    dfs(0, 0); // root at 0
    for(int j = 1; j < LgN; ++j) {
      for(int u = 0; u < N; ++u) {
        par[j][u] = par[j - 1][par[j - 1][u]];
        val[j][u] = op(val[j - 1][u], val[j - 1][par[j - 1][u]]);
      }
    }
  }
  pair<W, int> vlca(int u, int v) {
    if(lev[u] < lev[v]) {
      swap(u, v);
    }
    W value = id;
    for(int msk = lev[u] - lev[v], j = 0; msk; msk >>= 1, ++j) {
      if(msk & 1) {
        value = op(value, val[j][u]);
        u = par[j][u];
      }
    }
    if(u == v) {
      return {value, u};
    }
    for(int j = LgN - 1; j >= 0; --j) {
      if(par[j][u] != par[j][v]) {
        value = op(value, op(val[j][u], val[j][v]));
        u = par[j][u];
        v = par[j][v];
      }
    }
    return {op(value, op(val[0][u], val[0][v])), par[0][u]};
  }
  vector<int> path(int u, int v) {
    vector<int> p;
    int w = vlca(u, v).second;
    while(u != w) {
      p.push_back(u);
      u = par[0][u];
    }
    p.push_back(w);
    int s = p.size();
    while(v != w) {
      p.push_back(v);
      v = par[0][v];
    }
    reverse(p.begin() + s, p.end());
    return p;
  }
};
