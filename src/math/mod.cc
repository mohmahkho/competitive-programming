int const MOD = 1000 * 1000 * 1000 + 7;
int mod(int x) {
    x %= MOD;
    return x < 0 ? x + MOD : x;
}

// this mod function works for negative numbers as well
