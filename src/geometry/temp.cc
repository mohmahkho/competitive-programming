
template<typename T> struct Circle;
template<typename T> struct Line;
// --------------------------------
constexpr double eps = 1e-8;
template<typename T>
bool eq(const T& lhs, const T& rhs) {
  return lhs == rhs;
}
template<>
bool eq<float>(const float& lhs, const float& rhs) {
  return fabs(lhs - rhs) < eps;
}
template<>
bool eq<double>(const double& lhs, const double& rhs) {
  return fabs(lhs - rhs) < eps;
}
template<>
bool eq<long double>(const long double& lhs, const long double& rhs) {
  return fabs(lhs - rhs) < eps;
}
// --------------------------------
template<typename T = double>
struct Pt {
  T x, y;
  Pt() : x(T()), y(T()) {
  }
  Pt(T x_, T y_) : x(x_), y(y_) {
  }
  bool operator<(const Pt& other) const {
    if(x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }
  bool operator==(const Pt& other) const { return x == other.x && y == other.y; }
  bool operator<=(const Pt& other) const { return *this < other || *this == other; }
  bool operator>(const Pt& other) const { return !(*this <= other); }
  bool operator>=(const Pt& other) const { return !(*this < other); }
  Pt operator-(const Pt& other) const { return {x - other.x, y - other.y}; }
  Pt operator+(const Pt& other) const { return {x + other.x, y + other.y}; }
  Pt operator-() const { return {-x, -y}; }
  Pt operator+() const { return *this; }
  template<typename U>
  Pt operator*(U r) const { return {r * x, r * y}; }
  template<typename U, typename V>
  friend Pt operator*(V r, const Pt<U>& p) { return p * r; }
  template<typename U>
  friend ostream& operator<<(ostream& os, const Pt<U>& p) {
    return (os << '(' << p.x << ", " << p.y << ')');
  }

  typename common_type<T, long long>::type
  norm() const {
    using R = typename common_type<T, long long>::type;
    return (R) x * x + (R) y * y;
  }
};
// --------------------------------

template<typename T>
inline T dist2(const Pt<T>& p1, const Pt<T>& p2) {
  auto dx = p1.x - p2.x;
  auto dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

template<typename T = double>
inline T dist(const Pt<T>& p1, const Pt<T>& p2) {
  return sqrt(dist2(p1, p2));
}
// --------------------------------

template<typename T> typename common_type<long long, T>::type
cross_z(Pt<T> const& v1, Pt<T> const& v2) {
  using R = typename common_type<long long, T>::type;
  return (R) v1.x * v2.y - (R) v1.y * v2.x;
}

template<typename T> typename common_type<long long, T>::type
dot(Pt<T> const& v1, Pt<T> const& v2) {
  using R = typename common_type<long long, T>::type;
  return (R) v1.x * v2.x + (R) v1.y + v2.y;
}

template<typename T = double>
auto spin(Pt<T> const& a, Pt<T> const& b, Pt<T> const& c) {
  // spin of a -> b -> c
  // return > 0 : counterclockwise
  // return = 0 : collinear
  // return < 0 : clockwise
  return cross_z(b - a, c - a);
}
// --------------------------------

template<typename T = double>
struct Line {
  // ax + by + c = 0
  // (a, b) perpendicular to Line
  // (-b, a) collinear to Line
  T a, b, c;
  Line() : a(1), b(T()), c(T()) {
  }
  Line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {
  }
  Pt<T> closest_to_origin() const {
    // returns the point on the Lint which is closest to the origin
    T dnum = a * a + b * b;
    return {-a * c / dnum, -b * c / dnum};
  }
  Line translate(const Pt<T>& t) const {
    // translate this line with respect to vector t
    return {a, b, c - a * t.x - b * t.y};
  }
  Pt<T> closest_to(const Pt<T>& p) const {
    // returns the point on the Line which is closest to point p
    return translate(-p).closest_to_origin() + p;
  }

  vector<Pt<T>> intersect(const Circle<T>& circle) {
    auto p = closest_to(circle.center);
    auto r2 = circle.r * circle.r;

    if(eq(dist2(p, circle.center), r2)) {
      return {p};
    } else if(dist2(p, circle.center) > r2) {
      return {};
    } else {
      auto d2 = r2 - (p - circle.center).norm();
      auto vec = Pt<T>(-b, a) * sqrt(d2 / (a * a + b * b));
      return {p + vec, p - vec};
    }
  }
};

template<typename T = double>
struct Circle {
  T r;
  Pt<T> center;
  Circle() : center(), r(T()) {
  }
  Circle(T x_, T y_, T r_) : center(x_, y_), r(r_) {
  }
  vector<Pt<T>> intersect(const Circle& other) {
    return Line<T>(2 * (other.center.x - center.x),
                   2 * (other.center.y - center.y),
                   center.norm() - other.center.norm() - r * r + other.r * other.r)
           .intersect(*this);
  }
};
