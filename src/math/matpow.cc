constexpr int M = 1000000000 + 7;
 
vector<vector<int>> matmul(vector<vector<int>>& m1, vector<vector<int>>& m2, int n) {
  vector<vector<int>> res(n, vector<int>(n, 0));
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int k = 0; k < n; ++k) {
        res[i][j] += 1ll * m1[i][k] * m2[k][j] % M;
        if(res[i][j] >= M) res[i][j] -= M;
      }
    }
  }
  return res;
}
 
vector<vector<int>> matpow(vector<vector<int>> m, int b, int n) {
  vector<vector<int>> res(n, vector<int>(n));
  for(int i = 0; i < n; ++i) res[i][i] = 1;
  
  do {
    if(b & 1) res = matmul(res, m, n);
    m = matmul(m, m, n);
  } while(b >>= 1);
  return res;
}

/*
matpow takes a 0-based n * n matrix and return the b'th power of that modulo M.
O(n^3 * log(b))
*/
