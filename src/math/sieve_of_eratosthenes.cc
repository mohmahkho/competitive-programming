vector<int> sieve_of_eratosthenes(int n) {
  // least prime factor for all integers from 2..n - 1
  vector<int> lp(n);
  for(int i = 2; i < n; ++i) if(!lp[i]) {
    for(int j = i; j < n; j += i) if(!lp[j]) {
      lp[j] = i;
    }
  }
  return lp;
}
