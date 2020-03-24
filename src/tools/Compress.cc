struct Compress {
  vector<int> id;
  template<class InputIt>
  Compress(InputIt first, InputIt last) {
    vector<pair<typename iterator_traits<InputIt>::value_type, int>> aux;
    int idx = 0;
    for(auto it = first; it != last; ++it, ++idx) {
      aux.emplace_back(*it, idx);
    }
    id.assign(idx, 0);
    sort(aux.begin(), aux.end());
    int cnt = -1;
    for(int i = 0; i < aux.size(); ++i) {
      if(i == 0 || aux[i].first != aux[i - 1].first) ++cnt;
      id[aux[i].second] = cnt;
    }
  }
  int& operator[](int i) {
    return id[i];
  }
};
