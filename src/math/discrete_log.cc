int discrete_log(int a, int b, int m) {
  /* finds all 0 <= x < m 
   * a ^ x == b (mod m)
   * assumption : gcd(a, m) = 1
   * return only one instance
   */
  int n = sqrt(m) + 1;
  unordered_map<int, vector<int>> arcg;
  int an = 1;
  for(int q = 0; q < n; ++q) {
    arcg[1LL * an * b % m].push_back(q);
    an = 1LL * an * a % m;
  }
  for(int p = 1, f = an; p <= (m + n - 1) / n; ++p) {
    if(arcg.count(f)) {
      int q = arcg[f].back();
      int x = n * p - q;
      return x;
    }
    f = 1LL * f * an % m;
  }
  return -13; // not found
}

int general_discrete_log(int a, int b, int m) {
  /* Maybe gcd(a, m) > 1 */
  if(m == 1) return 0;
  if(a == 0) {
    if(b != 0) return -10;
    else return 0;
  }
  if(b == 1) return 0;
  int d = gcd(a, m);
  if(d == 1) return discrete_log(a, b, m);
  if(b % d != 0) return -110;
  m /= d;
  return 1 + general_discrete_log(a, (1LL * b / d * mpow(a / d, phi(m) - 1, m)) % m, m);
}
