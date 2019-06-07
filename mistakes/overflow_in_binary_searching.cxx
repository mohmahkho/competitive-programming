/*
When using binary search on a problem we usually have a L and R and we want to
test if middle element satisfies some boolean function f(mid). for this we may
do the following :
*/
int mid = (L + R) / 2;
/*
This may be an overflow.
Correct way:
*/
int mid = L + (R - L) / 2;
