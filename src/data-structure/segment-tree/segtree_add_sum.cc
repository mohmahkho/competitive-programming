template<typename T>
class segment_tree {
  struct node {
    T x, lazy;
    node() : x(), lazy() {
    }
    void add(T by) {
      x += by;
      lazy += by;
    }
  };
  inline int L(int v) { return v << 1; }
  inline int R(int v) { return L(v) + 1; }
 
  void push(int v) {
    if(tree[v].lazy) {
      tree[L(v)].add(tree[v].lazy);
      tree[R(v)].add(tree[v].lazy);
      tree[v].lazy = 0;
    }
  }
 
  int n;
  const T INF;
  vector<node> tree;
 
  T sumq(int ql, int qr, int v, int l, int r) {
    if(l > qr || ql > r) return 0;
    if(ql <= l && r <= qr) return tree[v].x;
    push(v);
    int m = (l + r) >> 1;
    return sumq(ql, qr, L(v), l, m) + sumq(ql, qr, R(v), m + 1, r);
  }
 
  void add(int ql, int qr, T by, int v, int l, int r) {
    if(l > qr || ql > r) return;
    if(ql <= l && r <= qr) {
      tree[v].add(by); 
    } else {
      push(v);
      int m = (l + r) >> 1;
      add(ql, qr, by, L(v), l, m);
      add(ql, qr, by, R(v), m + 1, r);
      tree[v].x = tree[L(v)].x + tree[R(v)].x;
    }
  }
 
public:
  segment_tree(int n_) : n(n_), INF(numeric_limits<T>::max() / 2) {
    tree.resize(n << 2);
  }
  T sumq(int ql, int qr) { return sumq(ql, qr, 1, 0, n - 1); }
  void add(int ql, int qr, T by) { add(ql, qr, by, 1, 0, n - 1); }   
};
