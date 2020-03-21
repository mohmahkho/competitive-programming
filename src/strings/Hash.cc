class Hash {
  const int B, M;
  vector<int> bi, h;
  int inv(int a) {
    int res = 1;
    for(int b = M - 2; b; a = 1LL * a * a % M) {
      if(b & 1) res = 1LL * res * a % M;
      b >>= 1;
    }
    return res;
  }
public:
  Hash(const string& s, int base, int mod) : B(base), M(mod) {
    bi.resize(s.size());
    h.assign(s.size(), 0);
    int b = inv(B);
    bi[0] = 1;
    for(int i = 1; i < s.size(); ++i) {
      bi[i] = 1LL * bi[i - 1] * b % M;
    }
    for(int i = 0, p = 1; i < s.size(); ++i, p = 1LL * p * B % M) {
      if(i) h[i] = h[i - 1];
      h[i] += 1LL * (s[i] - 'a') * p % M;
      if(h[i] >= M) h[i] -= M;
    }
  }
 
  int hash(int i, int j) {
    int ans = h[j];
    if(i) {
      ans -= h[i - 1];
      if(ans < 0) ans += M;
    }
    return 1LL * ans * bi[i] % M;
  }
};
 
class DoubleHash {
  Hash h1, h2;
public:
  DoubleHash(const string& s, int b1, int m1, int b2, int m2) :
    h1(s, b1, m1), h2(s, b2, m2)
  {
  }
 
  pair<int, int> hash(int i, int j) {
    return {h1.hash(i, j), h2.hash(i, j)};
  }
};
