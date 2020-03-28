namespace matrix {
template<typename T>
vector<vector<T>> operator*(const vector<vector<T>>& a, const vector<vector<T>>& b) {
  int n = (int) a.size();
  int m = (int) b[0].size();
  vector<vector<T>> res(n, vector<T>(m));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      for(int k = 0; k < a[i].size(); ++k) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}
template<typename T>
vector<vector<T>>& operator*=(vector<vector<T>>& a, const vector<vector<T>>& b) {
  return (a = a * b);
}
 
template<typename T>
vector<vector<T>> eye(int n) {
  vector<vector<T>> res(n, vector<T>(n));
  for(int i = 0; i < n; ++i) {
    res[i][i] = 1;
  }
  return res;
}
 
template <typename T, typename U = long long>
vector<vector<T>> pow(vector<vector<T>> a, U b) {
  int n = (int) a.size();
  auto res = eye<T>(n);
  do {
    if(b & 1) res *= a;
    a *= a;
  } while(b >>= 1);
  return res;
}
}
 
template<typename T, typename U = long long>
struct Rec {
  vector<T> u;
  vector<vector<T>> t;
  Rec(vector<T> x, vector<T> y, vector<T> b) {
    // seq: a[n] = x[0]a[n - k] + x[1]a[n - k + 1] + ... + x[k - 1]a[n - 1]
    //           + y[0] + y[1]n + y[2]n^2 + y[3]n^3 + ... + y[q - 1]n^(q - 1)
    // a[1] = b[0], a[2] = b[1], ..., a[k] = b[k - 1]
    int k = (int) x.size();
    int q = (int) y.size();
    t = vector<vector<T>>(k + q, vector<T>(k + q)); 
    for(int i = 0; i < k - 1; ++i) {
      t[i][i + 1] = 1;
    }
    for(int i = 0; i < k; ++i) {
      t[k - 1][i] = x[i];
    }
    for(int i = 0; i < q; ++i) {
      t[k - 1][k + i] = y[i];
    }
    for(int i = k; i < (k + q); ++i) {
      for(int j = k; j <= i; ++j) {
        if(i == k) { t[i][j] = 1; }
        else { t[i][j] = t[i - 1][j] + t[i - 1][j - 1]; }
      }
    }
    T w = 1;
    int n = (int) b.size() + 1;
    for(int i = 0; i < q; ++i) {
      b.push_back(w);
      w *= n;
    }
    u = move(b);
  }
  T term(U n) {
    using namespace matrix;
    auto tn = pow(t, n - 1);
    T ans = 0;
    for(int i = 0; i < tn.size(); ++i) {
      ans += tn[0][i] * u[i];
    }
    return ans;
  }
};
