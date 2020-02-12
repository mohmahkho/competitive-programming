namespace gauss {
  constexpr int M = 1000003;
  int add(int a, int b) {
    a += b;
    if(a >= M) a -= M;
    return a;
  }
  int sub(int a, int b) {
    a -= b;
    if(a < 0) a += M;
    return a;
  }
  int mul(int a, int b) {
    long long res = 1LL * a * b;
    if(res >= M) res %= M;
    return res;
  }
 
  int inv(int a) {
    int b = M - 2, res = 1;
    do {
      if(b & 1) res = mul(res, a);
      a = mul(a, a);
    } while(b >>= 1);
    return res;
  }
  vector<int> mul(int a, vector<int> v) {
    for(int i = 0; i < v.size(); ++i) {
      v[i] = mul(v[i], a);
    }
    return v;
  }
  vector<int> sub(vector<int> u, vector<int> v) {
    assert(u.size() == v.size());
    for(int i = 0; i < u.size(); ++i) {
      u[i] = sub(u[i], v[i]);
    }
    return u;
  }
 
  vector<int> elimination(vector<vector<int>>& a, int n) {
    // n equations, n variables in mod M
    // a is n * (n + 1)
    for(int j = 0; j < n; ++j) {
      int row = -1;
      for(int i = j; i < n; ++i) {
        if(a[i][j] != 0) {
          row = i;
          break;
        }
      }
      if(row == -1) continue; // has no answer
      if(row != j) swap(a[j], a[row]);
      a[j] = mul(inv(a[j][j]), a[j]);
      for(int i = 0; i < n; ++i) {
        if(i != j && a[i][j]) {
          a[i] = sub(mul(inv(a[i][j]), a[i]), a[j]);
        }
      }
    }
    vector<int> res(n);
    for(int i = 0; i < n; ++i) {
      assert(a[i][i] != 0);
      res[i] = mul(a[i][n], inv(a[i][i])); 
    }
    return res;
  }
}
