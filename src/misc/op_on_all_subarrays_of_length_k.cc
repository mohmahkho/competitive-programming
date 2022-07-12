template<typename T, typename F>
vector<T> k_subarray(const vector<T>& A, int k, const F& op) {
  if(k == 1) return A;
  int n = (int) A.size();
  vector<T> res(n - k + 1);
  // res[i] = op(A[i], A[i + 1], ..., A[i + k - 1])
  // op must sat : op(x, y) = op(y, x)
  auto calc = [&] (const auto& self, int l, int r) {
    if(r - l + 1 < k) return;
    int m = (l + r) / 2;
    self(self, l, m);
    self(self, m + 1, r);
    vector<T> left(k - 1);
    for(int i = m; i >= max(0, m - k + 2); --i) {
      left[m - i] = (i == m ? A[i] : op(A[i], left[m - i - 1]));
    }
    T pref;
    for(int i = m + 1; i <= min(m + k - 1, n - 1); ++i) {
      pref = (i == m + 1 ? A[i] : op(pref, A[i]));
      if(i - k + 1 >= 0) res[i - k + 1] = op(pref, left[k - i + m - 1]);
    }
  };
  calc(calc, 0, n - 1);
  return res;
} // O(n)
