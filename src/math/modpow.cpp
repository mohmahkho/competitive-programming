using ll = long long;
ll const MOD = 1'000'000'000 + 7;

ll mod(ll x) {
    return x < 0 ? x % MOD + MOD : x % MOD;
}

ll mpow(ll base, ll exp) {
    base = mod(base);
    ll res = 1;
    while(exp > 0) {
        if(exp & 1) res = mod(res * base);
        base = mod(base * base);
        exp >>= 1;
    }
    return res;
}
