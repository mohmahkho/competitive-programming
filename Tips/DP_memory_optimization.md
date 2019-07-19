**DP Memory Optimization**  
Sometimes we can optimize memory while using <img src="https://tex.s2cms.ru/svg/dp" alt="dp" /> technique. For example, if we have a <img src="https://tex.s2cms.ru/svg/dp" alt="dp" /> table with two dimensions, we may be able to remove one dimension and keep the same time complexity. An example of this would be knapsack problem in which we can solve it in two dimensional <img src="https://tex.s2cms.ru/svg/dp" alt="dp" /> like <img src="https://tex.s2cms.ru/svg/dp%5Bi%5D%5Bw%5D" alt="dp[i][w]" /> which <img src="https://tex.s2cms.ru/svg/i" alt="i" /> is the item we are on, and <img src="https://tex.s2cms.ru/svg/w" alt="w" /> is the weight we already have. But in filling this table we only need the previous index which means that <img src="https://tex.s2cms.ru/svg/dp%5Bi%5D%5Bw%5D" alt="dp[i][w]" /> will be filled using only <img src="https://tex.s2cms.ru/svg/dp%5Bi%20-%201%5D%5Bw%5Cprime%5D" alt="dp[i - 1][w\prime]" /> so we can get rid of the dimension that holds index and make this <img src="https://tex.s2cms.ru/svg/dp" alt="dp" /> table work like <img src="https://tex.s2cms.ru/svg/dp_i%5Bw%5D" alt="dp_i[w]" /> which means the best value with weight  <img src="https://tex.s2cms.ru/svg/w" alt="w" /> at the time we are on item <img src="https://tex.s2cms.ru/svg/i" alt="i" />. We loop through items from <img src="https://tex.s2cms.ru/svg/1" alt="1" /> to <img src="https://tex.s2cms.ru/svg/N" alt="N" /> and fill this table backwards so that we won't pick one item twice. Here is the code :  
```
int N, W;
cin >> N >> W;
vector<int> w(N), v(N);
vector<ll> dp(W + 1);
for(int j = 0; j < N; ++j) {
    cin >> w[j] >> v[j];
    for(int i = W; i >= 0; --i) {
        if(w[j] + i <= W) {
            dp[w[j] + i] = max(dp[w[j] + i], dp[i] + v[j]);
        }
    }
}
cout << *max_element(dp.begin(), dp.end()) << '\n';
```
