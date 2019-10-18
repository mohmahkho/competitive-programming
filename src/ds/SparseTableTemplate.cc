template<typename T, T id = 0>
class SparseTable {
    int n, l;
    vector<int> lg;
    vector<vector<T>> t;
    function<T(T, T)> f;
    bool idempotent = false;
    
    void fill_table() {
        for(int j = 1; j < l; ++j) {
            for(int i = 0; i + (1 << j) < n; ++i) {
                t[j][i] = f(t[j - 1][i], t[j - 1][i + (1 << j - 1)]); 
            }
        }
    }
    
    T q_idempotent(int i, int j) {
        assert(idempotent);
        int p = lg[j - i + 1];
        return f(t[p][i], t[p][j - (1 << p) + 1]);
    }
    
    T q(int i, int j) {
        assert(!idempotent);
        T res = id;
        do {
            int p = lg[j - i + 1];
            res = f(res, t[p][i]);
            i += 1 << p;
        } while(lg[j - i + 1]);
        return res; 
    }
 
public:
    SparseTable(const int* a, int n, function<T(T, T)> f) : n(n), f(f) {
        lg.resize(n + 1);
        for(int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
 
        l = lg[n] + 1;
        t = vector<vector<T>>(l, vector<T>(n));
 
        for(int i = 0; i < n; ++i) {
            t[0][i] = a[i];
        }
        fill_table();
        idempotent = f(3, 3) == 3;
    }
 
    SparseTable(const vector<T>& a, function<T(T, T)> f) :
    SparseTable(a.data(), (int) a.size(), f)
    {
    }
     
    T query(int i, int j) {
        assert(i <= j && 0 <= i && j < n);
        if(idempotent) return q_idempotent(i, j); // constant time
        else return q(i, j); // logarithmic time
    }
};
