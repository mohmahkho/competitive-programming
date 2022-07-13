class fen2d {
    int n, m;
    vector<vector<int>> bit;
public:
    fen2d(int n, int m) : n(n), m(m) {
        bit.assign(n, vector<int>(m, 0));
    }

    void add(int r, int c, int x) {
        for(int i = r; i < n; i = i | (i + 1)) {
            for(int j = c; j < m; j = j | (j + 1)) {
                bit[i][j] += x;
            }
        }
    }

    int sum(int r, int c) {
        int res = 0;
        for(int i = r; i >= 0; i = (i & (i + 1)) - 1) {
            for(int j = c; j >= 0; j = (j & (j + 1)) - 1) {
                res += bit[i][j];
            }
        }
        return res;
    }

    int sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) + sum(r1 - 1, c1 - 1) - sum(r1 - 1, c2) - sum(r2, c1 - 1);
    }
};
