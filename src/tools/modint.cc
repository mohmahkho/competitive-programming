template<int32_t Mod>
struct modint {
  using mod_t = decltype(Mod);
  static constexpr int m = Mod;
 
  template<typename T> mod_t mod(T n) const {
    if(n < 0 || n >= m) n %= m;
    if(n < 0) n += m;
    return static_cast<mod_t>(n);
  } 
  template<typename T> modint pow(T p) const {
    modint res(1), a(*this);
    do {
      if(p & 1) res *= a;
      a *= a;
    } while(p >>= 1);
    return res;
  }
  modint inv() const {
    return pow(m - 2);
  }
 
  modint() = default;
  modint(const modint& x): val(x.val) {}
  template<typename T> modint(T x): val(mod(x)) {}
 
  modint& operator=(const modint& x) { val = x.val; return *this; }
 
  modint& operator+=(const modint& x) { if((val += x.val) >= m) val -= m; return *this; }
  modint& operator-=(const modint& x) { if((val -= x.val) < 0) val += m; return *this; }
  modint& operator*=(const modint& x) { val = mod((int64_t) val * x.val); return *this; }
  modint& operator/=(const modint& x) { return *this *= x.inv(); }
 
  modint& operator++() { return *this += 1; }
  modint& operator--() { return *this -= 1; }
  modint operator++(int) { modint ret(*this); *this += 1; return ret; }
  modint operator--(int) { modint ret(*this); *this -= 1; return ret; }
  modint operator+() const { return *this; }
  modint operator-() const { return modint(m - val); }
 
  modint operator+(const modint& x) const { return modint(*this) += x; }
  modint operator-(const modint& x) const { return modint(*this) -= x; }
  modint operator*(const modint& x) const { return modint(*this) *= x; }
  modint operator/(const modint& x) const { return modint(*this) /= x; }
 
  template<typename T> modint operator+(T x) const { return *this + modint(x); }
  template<typename T> modint operator-(T x) const { return *this - modint(x); }
  template<typename T> modint operator*(T x) const { return *this * modint(x); }
  template<typename T> modint operator/(T x) const { return *this / modint(x); }
  template<typename T> modint& operator+=(T x) { return *this += modint(x); }
  template<typename T> modint& operator-=(T x) { return *this -= modint(x); }
  template<typename T> modint& operator*=(T x) { return *this *= modint(x); }
  template<typename T> modint& operator/=(T x) { return *this /= modint(x); }
 
  template<typename T> friend modint operator+(T a, const modint& b) { return b + a; }
  template<typename T> friend modint operator-(T a, const modint& b) { return -b + a; }
  template<typename T> friend modint operator*(T a, const modint& b) { return b * a; }
  template<typename T> friend modint operator/(T a, const modint& b) { return modint(a) / b; }
 
  friend ostream& operator<<(ostream& os, const modint& obj) { return os << obj.val; }
  friend istream& operator>>(istream& is, modint& obj) { int64_t x; is >> x; obj = modint(x); return is; }
 
  explicit operator mod_t() { return val; }
private:
  mod_t val = 0;
};
