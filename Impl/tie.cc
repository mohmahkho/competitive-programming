int fib(int n) {
  int a = 0, b = 1;
  for(int i = 1; i < n; ++i) {
    tie(a, b) = make_pair(b, a + b);
  }
  return b;
}
