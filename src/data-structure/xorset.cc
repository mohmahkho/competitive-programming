template<typename U = unsigned int>
class xorset {
  struct node { node* ch[2]{}; };
  node* root;

  void destroy(node*& v) {
    delete v;
    v = nullptr;
  }
  void insert(node* v, int j, U x) {
    if(j >= 0) {
      int b = x >> j & 1;
      insert(v->ch[b] ? v->ch[b] : v->ch[b] = new node(), j - 1, x);
    }
  }
  void erase(node*& v, int j, U x) {
    if(j == -1) destroy(v);
    else {
      int b = x >> j & 1;
      if(v->ch[b]) erase(v->ch[b], j - 1, x);
      if(!v->ch[0] && !v->ch[1] && v != root) destroy(v);
    }
  }
  U min_xor(node* v, int j, U x) {
    if(j == -1) return 0;
    int b = x >> j & 1;
    if(v->ch[b]) return min_xor(v->ch[b], j - 1, x);
    return (1ULL << j) ^ min_xor(v->ch[1 - b], j - 1, x);
  }
  void delete_tree(node*& v) {
    if(v->ch[0]) delete_tree(v->ch[0]);
    if(v->ch[1]) delete_tree(v->ch[1]);
    destroy(v);
  }
  
public:
  xorset() : root(new node()) {}
  void insert(U x) { insert(root, 8 * sizeof(U) - 1, x); }
  void erase(U x) { erase(root, 8 * sizeof(U) - 1, x); }
  U min_xor(U x) { return min_xor(root, 8 * sizeof(U) - 1, x); }
  ~xorset() { delete_tree(root); }
};
