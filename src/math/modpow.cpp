const int MOD = 1000 * 1000 * 1000 + 7;

int mod(long long x) {
    return (x % MOD + MOD) % MOD;
}

int modpow(int a, int b) {
    if (b == 0) return 1;
    int t = modpow(a, b / 2);
    if (b % 2 == 0) return mod(1LL * t * t);
    else return mod(1LL * mod(1LL * t * t) * a);
}
