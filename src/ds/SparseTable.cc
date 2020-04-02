template<typename T, bool idempotent, typename F = function<T(const T&, const T&)>>
struct SparseTable {
  int n;
  F f;
  vector<int> lg2;
  vector<vector<T>> t;
  SparseTable(const vector<T>& a, F f_)
  : n(a.size()), f(f_) {
    lg2.assign(n + 1, 0);
    for(int i = 2; i <= n; ++i) {
      lg2[i] = lg2[i >> 1] + 1;
    }
    t.assign(n, vector<T>(lg2[n] + 1));
    for(int i = 0; i < n; ++i) {
      t[i][0] = a[i];
    }
    for(int j = 1; j <= lg2[n]; ++j) {
      for(int i = 0; i + (1 << j) - 1 < n; ++i) {
        t[i][j] = f(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  void push_back(T x) {
    ++n;
    lg2.push_back(0);
    if(n >= 2) lg2[n] = lg2[n >> 1] + 1;

    t.push_back({x});
    for(int j = 1; j <= lg2[n]; ++j) {
      int i = n - (1 << j);
      if(t[i].size() <= j) t[i].push_back(T());
      t[i][j] = f(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    }
  } // O(lgn)
  
  template<bool trigger = idempotent>
  enable_if_t<trigger, T> query(int l, int r) {
    int j = lg2[r - l + 1];
    return f(t[l][j], t[r - (1 << j) + 1][j]);
  } // O(1)

  template<bool trigger = idempotent>
  enable_if_t<!trigger, T> query(int l, int r) {
    if(l == r) return t[l][0];
    int j = lg2[r - l + 1];
    if(l + (1 << j) - 1 == r) return t[l][j]; 
    return f(t[l][j], query(l + (1 << j), r));
  } // O(lgn)
};
