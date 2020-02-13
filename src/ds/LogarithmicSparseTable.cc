template<typename T>
struct SparseTable {
  const int n, lgn;
  const T id;
  vector<vector<T>> st;
  function<T(T, T)> op;
  SparseTable(const vector<T>& a, function<T(T, T)> f, T identity)
  : n(a.size()), lgn(log2(n) + 2), op(f), id(identity) {
    st.assign(lgn, vector<T>(n));
    for(int i = 0; i < n; ++i) {
      st[0][i] = a[i];
    }
    for(int j = 1; j < lgn; ++j) {
      for(int i = 0; i + (1 << j) - 1 < n; ++i) {
        st[j][i] = op(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]); 
      }
    }
  }
  T query(int l, int r) {
    T ans = id;
    for(int msk = r - l + 1, j = 0; msk; msk >>= 1, ++j) {
      if(msk & 1) {
        ans = op(ans, st[j][l]);
        l += 1 << j;
      }
    }
    return ans;
  }
};
