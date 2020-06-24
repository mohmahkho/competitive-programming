mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long random_inclusive(long long a, long long b) {
  return a + rng() % (b - a + 1);
}
