int constexpr A = 1e6 + 1;
int d[A]; // d[i] = number of divisors of i

for(int i = 1; i < A; ++i) {
    for(int j = i; j < A; j += i) d[j] += 1;
}

/*
Time Complexity:
time complexity of this algorithm is A * H(A) where H(n) is the n'th harmonic
harmonic series have logarithmic growth so time complexity is almost O(Alog(A))
*/
