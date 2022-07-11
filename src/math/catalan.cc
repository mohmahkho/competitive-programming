/*
the code below generates all well-formed parentheses.
the fact that all well-formed parentheses of lenght 2n equals the Cn
where Cn is the n'th catalan number makes this DP approach O(Cn) time.
considering this, parentheses(n, n).size() equals to the Cn.
*/

int constexpr N = 100;
vector<string> dp[N][N];

vector<string> parentheses(int r, int c) {
    if(r > c || r < 0 || c < 0) return {};
    if(r == 0 && c == 0) return {""};
    if(dp[r][c].size() != 0) return dp[r][c];
    vector<string>& ans = dp[r][c];
    for(string& s : parentheses(r - 1, c)) ans.push_back(s + ')');
    for(string& s : parentheses(r, c - 1)) ans.push_back(s + '(');
    return ans;
}

int main() {
    int n = 3;
    parentheses(n, n);
}


/*
the catalan number itself:
There is a recursive formula for n'th catalan number.
C(n) = (4n - 2) C(n - 1) / (n + 1)
*/
int cat[N];

int main() {
    int n;
    cin >> n;

    cat[0] = 1;
    for(int i = 1; i <= n; ++i) cat[i] = (4 * i - 2) * cat[i - 1] / (i + 1);
    cout << cat[n] << endl;
}
