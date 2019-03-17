int const N = 1009, MOD = 998244353;
int bc[N][N];

int bio(int n, int k) {
    if(k > n) return 0;
    if(bc[n][d] != 0) return bc[n][k];
    else return bc[n][k] = (bio(n - 1, k) + bio(n - 1, k - 1)) % MOD;
}

int main() {
    // setting base cases for bionomial coefficients
    for(int i = 0; i < N; ++i) {
        bc[i][0] = 1;
        bc[i][i] = 1;
    }
}
