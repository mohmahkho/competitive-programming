#include <bits/stdc++.h>
#define dump(x) cout << #x << " : " << x << endl
using namespace std;

template<typename T>
struct LineFunction {
  /* y = mx + b */
  T m, b;
  LineFunction() : m{T{}}, b{numeric_limits<T>::min()} {
  }
  LineFunction(T m_, T b_) : m{m_}, b{b_} {
  }
  template<typename U>
  typename common_type<U, T, long long>::type operator()(U x) {
    using R = typename common_type<U, T, long long>::type; 
    return (R) m * x + b;
  }
};

template<typename T>
class LiChaoTree { // max LiChao Tree
  vector<LineFunction<T>> tree;
  int min_x, max_x; // you can query x : min_x <= x <= max_x
  int mid(int l, int r) {
    return l + ((r - l) >> 1);
  }
  void insert(LineFunction<T> y, int v, int l, int r) {
    if(l == r) {
      if(tree[v](l) < y(l)) tree[v] = y;
      return;
    }
    int x = mid(l, r);
    if(y(x) > tree[v](x)) swap(y, tree[v]);

    if(y.m > tree[v].m) insert(y, 2 * v + 1, x + 1, r);
    else insert(y, 2 * v, l, x);
  }
  T query(int x, int v, int l, int r) {
    if(l == r) return tree[v](x);
    int mid_x = mid(l, r);
    if(x < mid_x) return max(tree[v](x), query(x, 2 * v, l, mid_x));
    return max(tree[v](x), query(x, 2 * v + 1, mid_x + 1, r));
  }
public:
  LiChaoTree(int min_x_, int max_x_) : min_x{min_x_}, max_x{max_x_} {
    tree.resize((max_x - min_x + 1) << 2);
  }
  void insert(LineFunction<T> y) {
    insert(y, 1, min_x, max_x);
  }
  T query(int x) {
    return query(x, 1, min_x, max_x);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  LiChaoTree<long long> lc(-100, 100);
  while(true) {
    int type;
    cin >> type;
    if(type == 1) {
      int m, b;
      cin >> m >> b;
      lc.insert(LineFunction<long long>(m, b), 1, -100, 100);
    } else {
      int x;
      cin >> x;
      cout << lc.query(x, 1, -100, 100) << endl;
    }
  }
}
