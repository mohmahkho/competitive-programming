template<typename T>
class segtree_admx {
  struct node {
    T mx = T();
    T lazy = T();
    void add(T by) {
      mx += by;
      lazy += by;
    }
  };
 
  void push(int v) {
    if(tree[v].lazy) {
      tree[2*v].add(tree[v].lazy);
      tree[2*v + 1].add(tree[v].lazy);
      tree[v].lazy = T();
    }
  }
 
  int n;
  vector<node> tree;
 
  T maxq(int ql, int qr, int v, int l, int r) {
    if(l > qr || ql > r) return -(numeric_limits<T>::max() / 2);
    if(ql <= l && r <= qr) return tree[v].mx;
    push(v);
    int m = (l + r)/2;
    return max(maxq(ql, qr, 2*v, l, m), maxq(ql, qr, 2*v + 1, m + 1, r));
  }
 
  void addq(int ql, int qr, T by, int v, int l, int r) {
    if(l > qr || ql > r) return;
    if(ql <= l && r <= qr) {
      tree[v].add(by); 
    } else {
      push(v);
      int m = (l + r)/2;
      addq(ql, qr, by, 2*v, l, m);
      addq(ql, qr, by, 2*v + 1, m + 1, r);
      tree[v].mx = max(tree[2*v].mx, tree[2*v + 1].mx);
    }
  }
 
public:
  segtree_admx(int n_) : n(n_) {
    tree.resize(4*n);
  }
  T maxq(int ql, int qr) {
    return maxq(ql, qr, 1, 0, n - 1);
  }
  void addq(int ql, int qr, T by) {
    addq(ql, qr, by, 1, 0, n - 1);
  }
};
