vector<int> kth_perm(int n, int64_t k) {
  vector<int64_t> fact(n + 1);
  vector<int> perm(n);
  fact[0] = 1;
  for(int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  for(int i = 0; i < n; ++i) {
    perm[i] = k / fact[n - 1 - i];
    k = k % fact[n - 1 - i];
  }
  for(int i = n - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      if (perm[j] <= perm[i]) perm[i]++;
    }
  }
  return perm;
  // kth_perm(4, 0) -> {0, 1, 2, 3}
  // kth_perm(4, 23) -> {3, 2, 1, 0}
}
