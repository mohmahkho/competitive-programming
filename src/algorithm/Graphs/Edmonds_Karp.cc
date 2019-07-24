#include <bits/stdc++.h>
using namespace std;

int constexpr N = 55, INF = 1e9 + 1000;
vector<vector<int>> g(N), cap(N, vector<int>(N));

int bfs(int s, int t) {
    vector<int> dist(N, INF), p(N), mn(N, INF);
    iota(begin(p), end(p), 0);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    bool found = false;
    while(!q.empty() && !found) {
        int u = q.front();
        q.pop();
        for(int v : g[u]) {
            if(cap[u][v] && dist[u] + 1 < dist[v]) {
                p[v] = u;
                dist[v] = dist[u] + 1;
                mn[v] = min(mn[u], cap[u][v]);
                q.push(v);
                if(v == t) {
                    found = true;
                    break;
                }
            }
        }
    }
    if(!found) return 0;
    int mnc = mn[t];
    while(p[t] != t) {
        cap[p[t]][t] -= mnc;
        cap[t][p[t]] += mnc;
        t = p[t];
    }
    return mnc;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // Construct graph in g
    // add flows in cap
    int s = 1, t = 10;
    // s is source / t is sink
    
    int ap, mf = 0;
    while(ap = bfs(s, t))
        mf += ap;
    cout << mf << '\n';
}
