template<typename T>
class merge_sort_tree {
  int n;
  const vector<T>& a;
  vector<vector<T>> tree;
 
  void build(int v, int l, int r) {
    if(l == r) {
      tree[v] = {a[l]};
    } else {
      int m = (l + r) / 2;
      build(2*v, l, m);
      build(2*v + 1, m + 1, r);
      merge(tree[2*v].begin(), tree[2*v].end(),
          tree[2*v + 1].begin(), tree[2*v + 1].end(),
          back_inserter(tree[v]));
    }
  }
 
  int leq(int v, int l, int r, int ql, int qr, T x) {
    if(ql > r || qr < l) return 0;
    if(ql <= l && r <= qr) return upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
    int m = (l + r) / 2;
    return leq(2*v, l, m, ql, qr, x) + leq(2*v + 1, m + 1, r, ql, qr, x);
  }
 
public:
  merge_sort_tree(const vector<T>& a_)
    : n(a_.size())
    , a(a_)
  {
    tree.resize(4 * n);
    build(1, 0, n - 1);
  }
 
  int leq(int ql, int qr, T x) {
    return leq(1, 0, n - 1, ql, qr, x);
  }
};
