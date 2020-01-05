constexpr int M = 1000000007;

int mpow(int a, int b) {
  int res = 1;
  do {
    cout << "here" << endl;
    if(b & 1) res = 1LL * a * res % M;
    a = 1LL * a * a % M;
  } while(b >>= 1);
  return res;
}

// mpow with negative exponent (b argument) will stuck in an infinite loop
// better to add assert(b >= 0)
