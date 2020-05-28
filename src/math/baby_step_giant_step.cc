/* author : mohmahkho
 * finds smallest x such that
 * a ^ x == b (mod m)
 * if no such x exists, returns -1
 * time complexity : O(sqrt(m) + log^2(m))
 * stress tested : check
*/
int discrete_log(int a, int b, int m) {
  int cnt = 0;
  int coprime = 1;
  for(int g = gcd(a, m); g != 1; g = gcd(a, m)) {
    if(b % g) {
      return -1;
    }
    m /= g;
    b /= g;
    coprime = 1LL * coprime * a / g % m;
    cnt += 1;
    if(coprime == b) {
      return cnt;
    }
  }
  int n = sqrt((double) m) + 1;
  int an = 1;
  unordered_map<int, int> idx;
  for(int q = 0; q < n; ++q) {
    idx[1LL * an * b % m] = q;
    an = 1LL * an * a % m;
  }
  for(int p = 1, f = 1LL * coprime * an % m; p <= (m + n - 1) / n; ++p) {
    if(idx.count(f)) {
      return p * n - idx[f] + cnt;
    }
    f = 1LL * f * an % m;
  }
  return -1;
}
