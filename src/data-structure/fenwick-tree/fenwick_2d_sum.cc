class Fenwick2D {
    int n, m;
    vector<vector<ll>> bit;
public:
    Fenwick2D(int n, int m) : n(n), m(m) {
        bit.assign(n + 5, vector<ll>(m + 5, 0));
    }

    void add(int r, int c, ll x) {
        for(int i = r; i <= n; i += i & -i) {
            for(int j = c; j <= m; j += j & -j) {
                bit[i][j] += x;
            }
        }
    }

    ll sum(int r, int c) {
        ll res = 0;
        for(int i = r; i > 0; i -= i & -i) {
            for(int j = c; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }
        return res;
    }

    ll sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) + sum(r1 - 1, c1 - 1) - sum(r1 - 1, c2) - sum(r2, c1 - 1);
    }
};
