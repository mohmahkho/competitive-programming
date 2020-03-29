struct LinearSieve {
  vector<int> primes, lpf;
  LinearSieve(int n) {
    lpf.assign(n, 0);
    for(int i = 2; i < n; ++i) {
      if(lpf[i] == 0) {
        lpf[i] = i;
        primes.push_back(i);
      }
      for(int p : primes) {
        if(i * p >= n) break;
        lpf[i * p] = p;
        if(i % p == 0) break;
      }
    }
  }
  bool is_p(int x) {
    return lpf[x] == x;
  }
  int p(int x) {
    return lpf[x];
  }
};
