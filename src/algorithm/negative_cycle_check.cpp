#include <bits/stdc++.h>
#define rep(i, a, comp, b)      for(auto i = a; i comp b; ++i)
#define per(i, a, comp, b)      for(auto i = a; i comp b; --i)
#define loop(i, a, comp, b, op) for(auto i = a; i comp b; i op)
#define repeat(t)               for(auto tmp__ = t; tmp__ > 0; --tmp__)
#define sz(x) ((int)sizeof(x))
#define pb push_back
#define eb emplace_back
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MAXINPUT = 1e5 + 10;
using ll  = long long;
using ull = unsigned long long;
using ii  = std::pair<int, int>;
template <class T>
using matrix = std::vector<std::vector<T>>;
using namespace std;

template<class T, class W>
using WAdjList = std::vector<std::vector<std::pair<T, W>>>;

int main()
{
    int n, m;
    cin >> n >> m;
    WAdjList<int, int> adj(n);
    vector<int> dist(n, INF);
    rep(i, 0, <, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(make_pair(v, w));
    }
    
    dist[0] = 0; // source is 0 and the shortest path for it is 0
    repeat(n-1) {
        rep(i, 0, <, n) {
            for(auto u : adj[i]) {
                int weight, vertex;
                tie(vertex, weight) = u;
                if(dist[i] + weight < dist[vertex])
                    dist[vertex] = dist[i] + weight;
            }
        }
    }

    rep(i, 0, <, n) {
        for(auto u : adj[i]) {
            int weight, vertex;
            tie(vertex, weight) = u;
            if(dist[i] + weight < dist[vertex]) {
                cout << "There is negative cycle." << endl;
                exit(0);
            }
        }
    }
    cout << "No negative cycle." << endl;
}
