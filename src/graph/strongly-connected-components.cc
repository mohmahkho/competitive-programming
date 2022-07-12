constexpr int N = 100009;
int n, m;
vector<vector<int>> g(N);
int num[N], low[N], vis[N];
stack<int> st;
 
void dfs(int u) {
    static int dn = 0;
    num[u] = low[u] = ++dn;
    vis[u] = 1;
    st.push(u);
    
    for(int v : g[u]) {
        if(vis[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v] == 1) {
            low[u] = min(low[u], num[v]);
        }
    }
 
    if(low[u] == num[u]) {
        // a strongly cc found
        while(true) {
            int v = st.top(); st.pop(); // v is in this cc
            vis[v] = 2;
            if(v == u) break;
        }
    }
}

int main() {
    // read the graph
    for(int v = 1; v <= n; ++v) {
        if(!vis[v]) dfs(v);
    }
}
