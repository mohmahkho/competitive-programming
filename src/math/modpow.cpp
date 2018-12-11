int modpow(int a, int b) {
  static int constexpr MOD = 1000000000 + 7;
  if(b == 0) {
    return 1;
  }
  int res = pow(a, b/2);
  res *= res;
  res %= MOD;
  if(b % 2 != 0) {
    res *= a;
    res %= MOD;
  }
  return res;
} // O(lg(b))
