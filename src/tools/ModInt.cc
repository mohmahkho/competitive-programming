template<int32_t Mod>
class ModInt {
public:
  using ModType = decltype(Mod);
  static constexpr int m = Mod;
 
  template<typename T> ModType mod(T n) const {
    if(n < 0 || n >= m) n %= m;
    if(n < 0) n += m;
    return static_cast<ModType>(n);
  } 
  template<typename T> ModInt pow(T p) const {
    ModInt res(1), a(*this);
    do {
      if(p & 1) res *= a;
      a *= a;
    } while(p >>= 1);
    return res;
  }
  ModInt inv() const {
    return pow(m - 2);
  }
 
  ModInt() = default;
  ModInt(const ModInt& other): val(other.val) {}
  template<typename T> ModInt(T n): val(mod(n)) {}
  ModInt& operator=(const ModInt& other) { val = other.val; return *this; }
 
  ModInt& operator+=(const ModInt& other) {
    if((val += other.val) >= m) val -= m; return *this; }
  ModInt& operator-=(const ModInt& other) {
    if((val -= other.val) < 0) val += m; return *this; }
  ModInt& operator*=(const ModInt& other) {
    val = mod((int64_t) (val) * (int64_t)(other.val)); return *this; }
  ModInt& operator/=(const ModInt& other) { return *this *= other.inv(); }
 
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator++(int) { ModInt ret(*this); *this += 1; return ret; }
  ModInt operator--(int) { ModInt ret(*this); *this -= 1; return ret; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(m - val); }
 
  ModInt operator+(const ModInt& other) const { return ModInt(*this) += other; }
  ModInt operator-(const ModInt& other) const { return ModInt(*this) -= other; }
  ModInt operator*(const ModInt& other) const { return ModInt(*this) *= other; }
  ModInt operator/(const ModInt& other) const { return ModInt(*this) /= other; }
 
  template<typename T> ModInt operator+(T other) const { return *this + ModInt(other); }
  template<typename T> ModInt operator-(T other) const { return *this - ModInt(other); }
  template<typename T> ModInt operator*(T other) const { return *this * ModInt(other); }
  template<typename T> ModInt operator/(T other) const { return *this / ModInt(other); }
  template<typename T> ModInt& operator+=(T other) { return *this += ModInt(other); }
  template<typename T> ModInt& operator-=(T other) { return *this -= ModInt(other); }
  template<typename T> ModInt& operator*=(T other) { return *this *= ModInt(other); }
  template<typename T> ModInt& operator/=(T other) { return *this /= ModInt(other); }
 
  template<typename T> friend
    ModInt operator+(T lhs, const ModInt& rhs) { return rhs + lhs; }
  template<typename T> friend
    ModInt operator-(T lhs, const ModInt& rhs) { return -rhs + lhs; }
  template<typename T> friend
    ModInt operator*(T lhs, const ModInt& rhs) { return rhs * lhs; }
  template<typename T> friend
    ModInt operator/(T lhs, const ModInt& rhs) { return ModInt(lhs) / rhs; }
 
  friend ostream& operator<<(ostream& os, const ModInt& m) { return (os << m.val); }
  friend istream& operator>>(istream& is, const ModInt& m) {
    int64_t n; is >> n; m.val = mod(n); return is; }
 
  explicit operator ModType() { return val; }
private:
  ModType val = 0;
};
