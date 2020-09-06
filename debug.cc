#include <bits/stdc++.h>
#define EVAL0(...) __VA_ARGS__
#define EVAL1(...) EVAL0(EVAL0(EVAL0(__VA_ARGS__)))
#define EVAL2(...) EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL3(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL4(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL(...)  EVAL4(EVAL4(EVAL4(__VA_ARGS__)))

#define MAP_END(...)
#define MAP_OUT
#define MAP_COMMA ,

#define MAP_GET_END2() 0, MAP_END
#define MAP_GET_END1(...) MAP_GET_END2
#define MAP_GET_END(...) MAP_GET_END1
#define MAP_NEXT0(test, next, ...) next MAP_OUT
#define MAP_NEXT1(test, next) MAP_NEXT0(test, next, 0)
#define MAP_NEXT(test, next)  MAP_NEXT1(MAP_GET_END test, next)

#define MAP0(f, x, peek, ...) f(x) MAP_NEXT(peek, MAP1)(f, peek, __VA_ARGS__)
#define MAP1(f, x, peek, ...) f(x) MAP_NEXT(peek, MAP0)(f, peek, __VA_ARGS__)

#define MAP_LIST_NEXT1(test, next) MAP_NEXT0(test, MAP_COMMA next, 0)
#define MAP_LIST_NEXT(test, next)  MAP_LIST_NEXT1(MAP_GET_END test, next)

#define MAP_LIST0(f, x, peek, ...) f(x) MAP_LIST_NEXT(peek, MAP_LIST1)(f, peek, __VA_ARGS__)
#define MAP_LIST1(f, x, peek, ...) f(x) MAP_LIST_NEXT(peek, MAP_LIST0)(f, peek, __VA_ARGS__)

#define MAP(f, ...) EVAL(MAP1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#define MAP_LIST(f, ...) EVAL(MAP_LIST1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#define BOX(x) std::string(std::string("[") + #x + " : " + to_string(x) + "]")
#define dump(...) debug_print_(MAP_LIST(BOX, __VA_ARGS__))

// usage : dump(a, b, c)

template<typename T>
std::string to_string(const std::vector<T>& v) {
  std::string res = "{";
  for(int i = 0; i < v.size(); ++i) {
    res += to_string(v[i]) + (i == (int) v.size() - 1 ? "" : ", ");
  }
  res += "}";
  return res;
}


template<typename T, typename U>
std::string to_string(const std::pair<T, U>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.secnod) + ")";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  return (os << to_string(v));
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return (os << to_string(p));
}

template<typename T>
void debug_print_(const T& x) {
  std::cerr << x << std::endl;
}
template<typename T, typename... Args>
void debug_print_(const T& x, Args... args) {
  std::cerr << x << ' ';
  debug_print_(args...);
}
