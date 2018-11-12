// Integer Type : int, long, long long, unsigned int, ...
template <class Integer>
Integer least_prime_factor(Integer n) {
    // returns smallest prime factor of n
    for(Integer i = 2; i * i <= n; i++) {
        if(n % i == 0) return least_prime_factor(i);
    }

    // n is prime
    return n;
}
