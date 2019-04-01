// we can use std::fill
int const N = 5000;
int dp[N][N];
fill((int*) dp, (int*) dp + N * N, -1);

// because every element that dp points to is an array of size [5000] so fill does not works
// but nevertheless dp is a pointer to the first of a one dimensional array of size 5000 * 5000
// because of row majority shape of the data in memory. so we can cast the type (pointer to [5000]) to the
// (pointer to int) and for the size part we need to add the size of the array which is 5000 * 5000
