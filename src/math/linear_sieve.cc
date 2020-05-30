vector<int> linear_sieve(int n) {
  vector<int> pr, lp(n);
  for(int i = 2; i < n; ++i) {
    if(!lp[i]) {
      lp[i] = i;
      pr.push_back(i);
    }
    for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < n; ++j) {
      lp[pr[j] * i] = pr[j];
    }
  }
  return lp;
}
