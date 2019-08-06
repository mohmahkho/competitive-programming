class Hash {
public:
  string & s;
  int n, B, M;
  vector<int> bi, h;

  Hash(string & _s, int _B, int _M) : s(_s), B(_B), M(_M) {
    n = (int) s.size();
    bi.resize(n);
    int b = mpow(B, M - 2, M);
    bi[0] = 1;
    for(int i = 1; i < n; ++i) {
      bi[i] = 1ll * bi[i - 1] * b % M;
    }
    h.assign(n, 0);
    for(int i = 0, p = 1; i < n; ++i, p = 1ll * p * B % M) {
      if(i) h[i] = h[i - 1];
      h[i] += 1ll * (s[i] - 'a') * p % M;
      if(h[i] >= M) h[i] -= M;
    }
  }

  int hash(int i, int j) {
    int ans = h[j];
    if(i) {
      ans -= h[i - 1];
      if(ans < 0) ans += M;
    }
    ans = 1ll * ans * bi[i] % M;
    return ans;
  }
};
