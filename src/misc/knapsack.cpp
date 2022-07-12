int N, W;
cin >> N >> W;
vector<int> w(N), v(N);
vector<long long> dp(W + 1);
for(int j = 0; j < N; ++j) {
    cin >> w[j] >> v[j];
    for(int i = W; i >= 0; --i) {
        if(w[j] + i <= W) {
            dp[w[j] + i] = max(dp[w[j] + i], dp[i] + v[j]);
        }
    }
}
cout << *max_element(dp.begin(), dp.end()) << '\n';
