struct hash_vector {
  const int B; // Base
  const int M; // Mod
  const int B_inv; // B^-1 mod M
  int N = 0; // size of string
  int B_pow; // B^(n-1) % M
  vector<int> B_inv_pow; // B_inv_pow[i] = B_inv^i mod M
  vector<int> H; // H[i] = S[0] * B^0 + ... + S[i] * B^i mod M 

  int inv(int a) {
    int res = 1;
    for(int b = M - 2; b; a = 1LL * a * a % M) {
      if(b & 1) res = 1LL * res * a % M;
      b >>= 1;
    }
    return res;
  }

  hash_vector(int B_, int M_)
    : B(B_)
    , M(M_)
    , B_inv(inv(B))
  {
  }

  void push_back(char x) {
    if(N == 0) {
      B_pow = 1;
      B_inv_pow.push_back(1);
    } else {
      B_pow = 1LL * B_pow * B % M;
      B_inv_pow.push_back(1LL * B_inv_pow[N - 1] * B_inv % M);
    }
    H.push_back(((N ? H[N - 1] : 0) + 1LL * B_pow * (x - 'a') % M) % M);
    ++N;
  }

  void pop_back() {
    B_inv_pow.pop_back();
    H.pop_back();
    B_pow = 1LL * B_pow * B_inv % M;
    --N;
  }

  int get_hash(int l, int r) {
    int res = H[r]; 
    if(l) {
      res -= H[l - 1];      
      if(res < 0) res += M;
    }
    return 1LL * res * B_inv_pow[l] % M;
  }
};
