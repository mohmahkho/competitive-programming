/*
let f be a function f : int -> bool
we know that if f(x) is true then f(x + 1) is also true
find minimum x in segment [a, b] that f(x) is true
if f(x) is not true for any integer in this segment print -1.
*/

int lb = a, ub = b;
int mid;
while(lb != ub) {
    mid = (lb + ub) / 2;
    if( f(mid) ) {
        ub = mid;
    } else {
        lb = mid + 1; // because we know f(mid) is false we skip it
    }
}

if(f(ub)) {
    cout << ub << endl;
} else {
    cout << -1 << endl;
}
