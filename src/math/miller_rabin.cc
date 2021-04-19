namespace miller_rabin {

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
// in case your compiler does not support __uint128_t, write a function similar
// to "mpow" for multiplication
uint64_t mpow(uint64_t a, uint64_t b, uint64_t mod) {
  uint64_t res = 1;
  a %= mod;
  do {
    if(b & 1) res = (__uint128_t)res * a % mod;
    a = (__uint128_t)a * a % mod;
  } while(b >>= 1);
  return res;
}

bool check_composite(uint64_t n, uint64_t a, uint64_t d, int s) {
  uint64_t x = mpow(a, d, n);
  if(x == 1 || x == n - 1) return false;
  for(int r = 1; r < s; r++) {
    x = (__uint128_t)x * x % n;
    if(x == n - 1) return false;
  }
  return true;
}

bool is_prime(uint64_t n, int iter = 14) {
 // returns true if n is probably prime, else returns false.
  if(n < 4) return n == 2 || n == 3;

  int s = 0;
  uint64_t d = n - 1;
  while((d & 1) == 0) {
    d >>= 1;
    s++;
  }

  for(int i = 0; i < iter; i++) {
    uint64_t a = 2 + rng() % (n - 3);
    if(check_composite(n, a, d, s)) return false;
  }
  return true;
}

}
