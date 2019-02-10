int least_prime_factor(int n) {
    // returns smallest prime number that devides n
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return i; // i is a prime factor of n
    }

    // n is prime
    return n;
}
