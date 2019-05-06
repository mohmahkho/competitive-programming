#define Matrix(n, m) vector<vector<int>>(n, vector<int>(m))
using Matrix = vector<vector<int>>;
int constexpr MOD = 1000 * 1000 * 1000 + 7;

int mod(int x) {
    x %= MOD;
    return x < 0 ? x + MOD : x;
}

Matrix mul(Matrix& a, Matrix& b, int n) {
    Matrix c = Matrix(n + 1, n + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k) {
                c[i][j] += mod(a[i][k] * b[k][j]);
                c[i][j] = mod(c[i][j]);
            }
    return c;
}

Matrix matpow(Matrix& base, int n, int exp) {
    // m is a n * n matrix
    Matrix res = Matrix(n + 1, n + 1);
    for(int i = 1; i <= n; ++i) res[i][i] = 1;
    while(exp > 0) {
        if(exp & 1) res = mul(res, base, n);
        base = mul(base, base, n);
        exp >>= 1;
    }
    return res;
}

/*
matpow return takes a 1-based n * n matrix and return the expth power of that
in modula MOD with time complexity of O(n^3 * log(exp))
*/
