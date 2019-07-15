int constexpr N = 5009;
vector<int> s(N); // holds stirling numbers of second type
vector<int> b(N); // holds bell numbers
s[0] = 1;
b[0] = 1;

for(int n = 1; n < N; ++n) {
    vector<int> s2(N);
    for(int k = 0; k <= n; ++k) {
        // {n, k}
        s2[k] = k * s[k] + (k ? s[k - 1] : 0);
        b[n] += s2[k];
    }
    swap(s2, s);
}
