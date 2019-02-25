const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int modpow(int a, int b) {
    if (b == 0) return 1;
    int t = modpow(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}
