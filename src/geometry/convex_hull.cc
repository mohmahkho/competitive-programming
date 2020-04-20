namespace geo2d {

template<typename T>
vector<Pt<T>> convex_hull(vector<Pt<T>> a) {
  if(a.size() == 1) {
    return a;
  }
  sort(a.begin(), a.end());
  vector<Pt<T>> up {a[0]}, dw {a[0]};
  for(int i = 1; i < a.size(); ++i) {
    while(up.size() >= 2 && spin(up[up.size() - 2], up[up.size() - 1], a[i]) >= 0) {
      up.pop_back();
    }
    while(dw.size() >= 2 && spin(dw[dw.size() - 2], dw[dw.size() - 1], a[i]) <= 0) {
      dw.pop_back();
    }
    up.push_back(a[i]);
    dw.push_back(a[i]);
  }
  auto hull = move(dw);
  for(int i = (int) up.size() - 2; i >= 1; --i) {
    hull.push_back(up[i]);
  }
  return hull;
}

}
