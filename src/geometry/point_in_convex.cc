template<typename T> 
struct PointInConvex {
  using Pt = Point2D<T>;
  vector<Pt> convex; // counterclockwise convex
  PointInConvex(vector<Pt> convex_) : convex(convex_) {
  }   

  bool inside_or_on_boundary(Pt p) {
    int lo = 1, hi = (int) convex.size() - 1;
    while(hi != lo) {
      int mid = (hi + lo + 1) / 2;
      if(signed_area(convex[0], convex[mid], p) >= 0) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    T orient = signed_area(convex[0], convex[lo], p);
    if(orient < 0) {
      return false;
    }
    if(lo == (int) convex.size() - 1) {
      if(orient > 0) {
        return false;
      } else {
        T u = (convex[lo] - convex[0]).dot(p - convex[0]);
        T v = (convex[lo] - convex[0]).dot(convex[lo] - convex[0]);
        return (u > 0 && v > 0 && u < v);
      }
    }
    return signed_area(convex[lo], convex[lo + 1], p) >= 0;
  } // O(logn)
};
