int pow(int a, int b) {
  if(b == 0) {
    return 1;
  }
  int halfpow = pow(a, b/2);
  return halfpow * halfpow * (b % 2 == 0 ? 1 : a);
} // O(lg(b))
