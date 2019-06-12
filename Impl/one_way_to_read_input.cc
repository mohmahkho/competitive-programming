/*
suppose reading input is in the following format:
N
x[1] y[1] h[1]
x[2] y[2] h[2]
.
.
.
x[N] y[N] h[N]
*/
#define fi first
#define se second
int main() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> p(n);
    for(auto& x : p) cin >> x.fi.fi >> x.fi.se >> x.se;
}
