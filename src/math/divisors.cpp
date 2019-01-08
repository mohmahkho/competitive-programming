// returns a vector of all divisors of n
// O(sqrt(n))
vector<int> divisors(int n)
{
    vector<int> divs;
    int sqrt_n = (int) sqrt(n);
    
    for(int d = 1; d <= sqrt_n; ++d) {
        if(n % d != 0) continue;
        divs.push_back(d);
        
        int q = n / d;
        if(q != d) divs.push_back(q);
    }

    return divs;
}
