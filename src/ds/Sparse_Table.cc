#include <bits/stdc++.h>
using namespace std;

int constexpr N = 100009;
int constexpr K = log2(N) + 10;
int n, q, v[N], sparse[N][K];


int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> v[i], sparse[i][0] = v[i];

    for(int j = 1; (1 << j) <= n; ++j) {
        int l = (1 << j);
        for(int i = 1; i <= n - l + 1; ++i) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + l / 2][j - 1]);
        }
    }

    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        ++a, ++b;
        int p = log2(b - a + 1);
        int ans = min(sparse[a][p], sparse[b - (1 << p) + 1][p]);
        cout << ans << endl;
    }
}
