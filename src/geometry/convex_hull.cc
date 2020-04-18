namespace geo {

template<typename T>
struct Point2D {
  T x, y;
  bool operator<(const Point2D& other) {
    if(x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }
  bool operator==(const Point2D& other) {
    return x == other.x && y == other.y;
  }
};

template<typename T>
T signed_area(Point2D<T> a, Point2D<T> b, Point2D<T> c) {
  return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

template<typename T>
vector<Point2D<T>> convex_hull(vector<Point2D<T>> a) {
  if(a.size() == 1) {
    return a;
  }
  using Pt = typename decltype(a)::value_type;
  sort(a.begin(), a.end());
  auto get_hull = [&a] (auto ok) {
    decltype(a) h { a[0] };
    for(int i = 1; i < a.size(); ++i) {
      while(h.size() >= 2 && !ok(h[h.size() - 2], h[h.size() - 1], a[i])) {
        h.pop_back();
      }
      h.push_back(a[i]);
    }
    return h;
  };
  decltype(a) res = 
    get_hull([](Pt p1, Pt p2, Pt p3) {return signed_area(p1, p2, p3) < 0;});
  res.pop_back();
  reverse(res.begin(), res.end());
  res.pop_back();
  for(auto p : get_hull([](Pt p1, Pt p2, Pt p3) {return signed_area(p1, p2, p3) > 0;})) {
    res.push_back(p);
  }
  return res;
}

} // end of namespace geo
