int n, m, dn;
vector<vector<int>> g;
vector<int> num, low, vis, art;

void dfs(int u, int p) {
    vis[u] = 1;
    num[u] = low[u] = dn++;

    int nkids = 0;
    
    for(int v : g[u]) {
        if(v == p) continue;
        if(vis[v]) {
            low[u] = min(low[u], num[v]);
        }
        if(!vis[v]) {
            nkids++;
            dfs(v, u);

            if(low[v] >= num[u]) art[u] = 1;
            low[u] = min(low[u], low[v]);
        }
    }
    if(u == 1) art[u] = nkids > 1;
}

void solve() {
    g.clear();
    g.resize(n + 1);

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vis.assign(n + 1, 0);
    num.assign(n + 1, 0);
    low.assign(n + 1, 0);
    art.assign(n + 1, 0);

    dn = 1;
    dfs(1, -1);
    cout << accumulate(art.begin(), art.end(), 0) << '\n';
}
