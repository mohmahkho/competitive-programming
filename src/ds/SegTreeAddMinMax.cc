template<typename T>
class SegTreeAddMinMax {
  struct Node {
    T x, y, lazy; // x : max, y : min
    Node() : x(), y(), lazy() {
    }
    void add(T by) {
      x += by;
      y += by;
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
  vector<Node> tree;
 
  T minq(int ql, int qr, int v, int l, int r) {
    if(l > qr || ql > r) return INF;
    if(ql <= l && r <= qr) return tree[v].y;
    push(v);
    int m = (l + r) >> 1;
    return min(minq(ql, qr, L(v), l, m), minq(ql, qr, R(v), m + 1, r));
  }
 
  T maxq(int ql, int qr, int v, int l, int r) {
    if(l > qr || ql > r) return -INF;
    if(ql <= l && r <= qr) return tree[v].x;
    push(v);
    int m = (l + r) >> 1;
    return max(maxq(ql, qr, L(v), l, m), maxq(ql, qr, R(v), m + 1, r));
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
      tree[v].x = max(tree[L(v)].x, tree[R(v)].x);
      tree[v].y = min(tree[L(v)].y, tree[R(v)].y);
    }
  }
 
public:
  SegTreeAddMinMax(int n) : n(n), INF(numeric_limits<T>::max() >> 1) {
    tree.resize(n << 2);
  }
  T minq(int ql, int qr) { return minq(ql, qr, 1, 0, n - 1); }
  T maxq(int ql, int qr) { return maxq(ql, qr, 1, 0, n - 1); }
  void add(int ql, int qr, T by) { add(ql, qr, by, 1, 0, n - 1); }   
};
