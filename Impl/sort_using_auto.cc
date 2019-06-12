#define fi first
#define se second
int n;
cin >> n;
vector<pair<pair<int, int>, int>> p(n);
sort(p.begin(), p.end(), [](auto& x, auto& y) { return x.se > y.se; });

// no need to specify types in lambda
