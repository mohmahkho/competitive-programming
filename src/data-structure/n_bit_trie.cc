template<typename T>
class n_bit_trie {
  struct node { array<unique_ptr<node>, 2> child; };
  int n;
  unique_ptr<node> root;
 
  void insert(unique_ptr<node>& u, int j, T x) {
    if(j >= 0) { 
      int bit = x >> j & 1;
      if(!u->child[bit]) u->child[bit] = make_unique<node>();
      insert(u->child[bit], j - 1, x);
    }
  }
 
  T min_xor(const unique_ptr<node>& u, int j, T x) {
    if(j < 0) return 0;
    int bit = x >> j & 1;
    if(u->child[bit]) {
      return min_xor(u->child[bit], j - 1, x);
    }
    return (1LL << j) + min_xor(u->child[1 - bit], j - 1, x);
  }
public:
  n_bit_trie(int n_) : n(n_) { root = make_unique<node>(); }
  void insert(T x) { insert(root, n - 1, x); }
  T min_xor(T x) { return min_xor(root, n - 1, x); }
};
