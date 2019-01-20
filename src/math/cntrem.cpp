// Count the number of numbers between 0..n inclusive that have remainder r int modula m
inline int cntrem(int n, int m, int r) {
    assert(0 <= r && r < m);
    return (r <= n % m) ? (n / m + 1) : (n / m);
} // O(1)

/* Logic :
    devide numbers in number line into groups of remainders for example for 3:
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, ...
    if we devide any number in any group by m, we get (because this is an integer division)
    we'll get the number of blocks before this block.
    so if this block has the number that has remainder r in modula m (r <= n % m)
        add this block to answer (n / m + 1)
    otherwise
        don't (n / m)
*/
