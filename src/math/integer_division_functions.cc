inline int64_t div_to_zero(int64_t n, int64_t d) {
  return n / d;
}
inline int64_t div_up(int64_t n, int64_t d) {
    return n / d + (((n < 0) ^ (d > 0)) && (n % d));
}
inline int64_t div_down(int64_t n, int64_t d) {
    return n / d - (((n > 0) ^ (d > 0)) && (n % d));
}
inline int64_t div_to_nearest(int64_t n, int64_t d) {
    return (2*n - d + 2*(true&&(n<0^d>0))*d) / (2*d); 
} //it however rounds numbers like +/- 3.5 towards 0 and not even.
