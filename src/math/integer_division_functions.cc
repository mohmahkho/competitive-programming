int div_to_zero(int n, int d) { return n / d; }
//as per C++11 standard note 80

int div_up(int n, int d) {
    return n / d + (((n < 0) ^ (d > 0)) && (n % d));
} //i.e. +1 iff (not exact int && positive result)

int div_down(int n, int d) {
    return n / d - (((n > 0) ^ (d > 0)) && (n % d));
} //i.e. +1 iff (not exact int && negative result)

int div_to_nearest(int n, int d) {
    return (2*n - d + 2*(true&&(n<0^d>0))*d) / (2*d); 
} //i.e. +-0.5 as per pre-rounding result sign, then div_to-zero 
//it however rounds numbers like +/- 3.5 towards 0 and not even.
