template<typename T>
struct unordered_dsu {
  unordered_map<T, T> p;
  T find(T v) {
    if(p.find(v) == p.end()) {
      p[v] = -1;
    }
    return p[v] < 0 ? v : p[v] = find(p[v]);
  }
  int unite(T u, T v) {
    u = find(u);
    v = find(v);
    if(u != v) {
      if(p[u] < p[v]) swap(u, v);
      p[v] += p[u];
      p[u] = v;
      return 1;
    }
    return 0;
  }
};
