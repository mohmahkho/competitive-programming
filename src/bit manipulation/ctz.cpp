// count trailing zeros
// __builtin_ctz in gcc
// 000010010000
// --------^^^^ : 4
int ctz(int n) {
    int msk = 1, tz = 0;
    for(int i = 0; i < sizeof(int) * 8; ++i, n >>= 1) {
        if(n & msk) return tz;
        ++tz;
    }
    return tz;
}

// template version
template <class Int>
int ctz(Int n) {
    Int msk = 1, tz = 0;
    for(Int i = 0; i < sizeof(Int) * 8; ++i, n >>= 1) {
        if(n & msk) return tz;
        ++tz;
    }
    return tz;
}
