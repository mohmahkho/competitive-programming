namespace geo2d {
template<typename T>
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
  bool operator==(const Pt& other) const {
    return x == other.x && y == other.y;
  }
  bool operator<=(const Pt& other) const {
    return *this < other || *this == other;
  }
  bool operator>(const Pt& other) const {
    return !(*this <= other);
  }
  bool operator>=(const Pt& other) const {
    return !(*this < other);
  }
  Pt operator-(const Pt& other) const {
    return {x - other.x, y - other.y};
  }
  Pt operator+(const Pt& other) const {
    return {x + other.x, y + other.y};
  }
};

template<typename T>
Pt<T> operator+(Pt<T> a, Pt<T> b) {
  return {a.x + b.x, a.y + b.y};
}

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

template<typename T>
auto spin(Pt<T> const& a, Pt<T> const& b, Pt<T> const& c) {
  // spin of a -> b -> c
  // return > 0 : counterclockwise
  // return = 0 : collinear
  // return < 0 : clockwise
  return cross_z(b - a, c - a);
}
}
