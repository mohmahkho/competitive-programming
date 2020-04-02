template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  template<typename... Args>
  Vec(int n, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {

  }
};
template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n, T val = T()) : vector<T>(n, val) {
  }
};
