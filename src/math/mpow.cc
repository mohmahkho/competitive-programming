int MOD = 1e9 + 7;

// Non-Rec
int mpow(int a, int b) {
    int res = 1;
    do {
        if(b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
    } while(b >>= 1);
    return res;
}

// Rec
int mpow(int a, int b) {
    if(!b) return 1;
    int ans = mpow(a, b >> 1);
    ans = 1ll * ans * ans % MOD;
    if(b & 1) ans = 1ll * ans * a % MOD;
    return ans;
}
