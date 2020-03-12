template<int32_t Mod>
struct ModInt {
  using ModType = decltype(Mod);
  template<typename T> ModType modify(T n) const {
    if(n < 0 || n >= Mod) { n %= Mod; }
    if(n < 0) { n += Mod; }
    return static_cast<ModType>(n);
  } 
  template<typename T>
  ModInt pow(T p) const {
    ModInt res {1}, a = *this;
    do {
      if(p & 1) { res *= a; }
      a *= a;
    } while(p >>= 1);
    return res;
  }
  ModInt inv() const {
    return pow(Mod - 2);
  }
 
  ModInt() = default;
  ModInt(const ModInt& other) { val = other.val; }
  ModInt(ModInt&& other) { val = other.val; }
  ModInt& operator=(const ModInt& other) { this->val = other.val; return *this; }
  ModInt& operator=(const ModInt&& other) { this->val = other.val; return *this; }
  template<typename T> ModInt(T n) { val = modify(n); }
 
  ModInt& operator+=(const ModInt& other) { if((val += other.val) >= Mod) val -= Mod; return *this; }
  ModInt& operator-=(const ModInt& other) { if((val -= other.val) < 0) val += Mod; return *this; }
  ModInt& operator*=(const ModInt& other) { val = modify((int64_t) (val) * (int64_t)(other.val)); return *this; }
  ModInt& operator/=(const ModInt& other) { return *this *= other.inv(); }
 
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator++(int) { ModInt res{*this}; *this += 1; return res; }
  ModInt operator--(int) { ModInt res{*this}; *this -= 1; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt{Mod - val}; }
 
  ModInt operator+(const ModInt& other) const { return ModInt(*this) += other; }
  ModInt operator-(const ModInt& other) const { return ModInt(*this) -= other; }
  ModInt operator*(const ModInt& other) const { return ModInt(*this) *= other; }
  ModInt operator/(const ModInt& other) const { return ModInt(*this) /= other; }
  ModInt operator+(const ModInt&& other) const { return ModInt(*this) += other; }
  ModInt operator-(const ModInt&& other) const { return ModInt(*this) -= other; }
  ModInt operator*(const ModInt&& other) const { return ModInt(*this) *= other; }
  ModInt operator/(const ModInt&& other) const { return ModInt(*this) /= other; }
 
  template<typename T> ModInt operator+(T other) const { return *this + ModInt(other); }
  template<typename T> ModInt operator-(T other) const { return *this - ModInt(other); }
  template<typename T> ModInt operator*(T other) const { return *this * ModInt(other); }
  template<typename T> ModInt operator/(T other) const { return *this / ModInt(other); }
  template<typename T> ModInt& operator+=(T other) { return *this += ModInt(other); }
  template<typename T> ModInt& operator-=(T other) { return *this -= ModInt(other); }
  template<typename T> ModInt& operator*=(T other) { return *this *= ModInt(other); }
  template<typename T> ModInt& operator/=(T other) { return *this /= ModInt(other); }
 
  friend ostream& operator<< (ostream& os, const ModInt& m) { return (os << m.val); }
  friend istream& operator>> (istream& is, const ModInt& m) {
    int64_t n;
    is >> n;
    m.val = modify(n);
    return is;
  }
 
  explicit operator ModType() { return val; }
private:
  ModType val = 0;
};
