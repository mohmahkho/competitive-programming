/* author : mohmahkho
 * finds smallest x such that
 * a ^ x == b (mod m)
 * if no such x exists, returns -1
 * time complexity : O(sqrt(m) + log^2(m))
 * stress tested : check
*/

// [Baby-step Giant-step] Smallest integer x such that a^x = b (mod m)
int discrete_log(int a, int b, int m) {
  a %= m; b %= m;
  if(b == 1) {
    return 0;
  }
  int cnt = 0, coprime = 1;
  for(int g = gcd(a, m); g != 1; g = gcd(a, m)) {
    if(b % g) {
      return -1;
    }
    m /= g; b /= g;
    coprime = 1ll * coprime * a / g % m;
    cnt += 1;
    if(coprime == b) {
      return cnt;
    }
  }
  int n = (int)sqrt((double)m) + 1;
  // a^np = b * a^q (mod m)
  unordered_map<int, int> q_of;
  int right = b, an = 1;
  for(int q = 0; q <= n; ++q) {
    q_of[right] = q;
    right = 1ll * right * a % m;
    if(q) an = 1ll * an * a % m;
  }
  for(int p = 1, left = 1ll * coprime * an % m; p * n < m + n; ++p) {
    if(q_of.count(left)) {
      return n * p - q_of[left] + cnt;
    }
    left = 1ll * left * an % m;
  }
  return -1;
}
