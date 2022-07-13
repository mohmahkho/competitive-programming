template<typename U>
struct bit {
  constexpr static int N = numeric_limits<U>::digits;
  constexpr static auto val(U x, int j) { return (int)(x >> j & U(1)); }
  constexpr static auto is_pow2(U x) { return x != 0 && (x & (x - 1)) == 0; }
  constexpr static auto set(U x, int j) { return U(1) << j | x; }
  constexpr static auto reset(U x, int j) { return ~(U(1) << j) & x; }
  constexpr static auto flip(U x, int j) { return U(1) << j ^ x; }
  constexpr static auto flip(U x) { return ~x; }
  constexpr static auto ones() { return U(-1); }
  constexpr static auto ones(int len) { return (len < N ? U(1) << len : 0) - U(1); }
  constexpr static auto ones(int l, int r) { return ones(r + 1) ^ ones(l); }
  constexpr static auto flip(U x, int l, int r) { return ones(l, r) ^ x; }
  constexpr static auto set(U x, int l, int r) { return ones(l, r) | x; }
  constexpr static auto reset(U x, int l, int r) { return ~(ones(l, r)) | x; }
  constexpr static auto next_submask(U mask, U cur) { return (cur - 1) & mask; }
  constexpr static auto next_overmask(U mask, U cur) { return (cur + 1) | mask; }
  constexpr static auto rotl(U x, int s) -> U {
    s %= N;
    if(!s) { return x; }
    if(s < 0) { s += N; }
    return x << s | x >> N - s;
  }
  constexpr static auto rotr(U x, int s) -> U {
    s %= N;
    if(!s) { return x; }
    if(s < 0) { s += N; }
    return x >> s | x << N - s;
  }
  constexpr static auto popcnt(U x) {
    if constexpr(is_same<unsigned, U>::value) {
      return __builtin_popcount(x);
    }
    return __builtin_popcountll(x);
  }
  constexpr static auto clz(U x) {
    if constexpr(is_same<unsigned, U>::value) {
      return __builtin_clz(x);
    }
    return __builtin_clzll(x);
  }
  constexpr static auto ctz(U x) {
    if constexpr(is_same<unsigned, U>::value) {
      return __builtin_ctz(x);
    }
    return __builtin_ctzll(x);
  }
  constexpr static auto log2(U x) {
    return N - clz(x);
  }
};
