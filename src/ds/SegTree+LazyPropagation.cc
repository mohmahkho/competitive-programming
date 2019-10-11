/* This version of segment tree has add range update query and maximum range query. */
constexpr int N = 200009;
ll x[N], s[N << 2], lazy[N << 2];

inline int L(int v) {return v << 1;}
inline int R(int v) {return L(v) + 1;}

void build(int v, int l, int r) {
    if(l == r) {
        s[v] = x[l];
    } else {
        int m = l + r >> 1;
        build(L(v), l, m); 
        build(R(v), m + 1, r);
        s[v] = max(s[L(v)], s[R(v)]);
    }
}

void push(int v) {
    if(!lazy[v]) return;
    lazy[L(v)] += lazy[v];
    s[L(v)] += lazy[v];
    lazy[R(v)] += lazy[v];
    s[R(v)] += lazy[v];
    lazy[v] = 0;
}

ll mx(int v, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return 0;
    if(ql <= l && r <= qr) return s[v];
    push(v);
    int m = l + r >> 1;
    return max(mx(L(v), l, m, ql, qr), mx(R(v), m + 1, r, ql, qr));
}

void add(int v, int l, int r, int ql, int qr, ll value) {
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr) {
        lazy[v] += value;
        s[v] += value;
    } else {
        push(v);
        int m = l + r >> 1;
        add(L(v), l, m, ql, qr, value);
        add(R(v), m + 1, r, ql, qr, value);
        s[v] = max(s[L(v)], s[R(v)]);
    }   
}
