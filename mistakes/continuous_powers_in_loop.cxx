/*
let's say we need continuous powers of some number p in a loop.
the most simple thing is to print them.
*/

// bad

int p = 2;
while(condition) {
    cout << p << endl;
    p *= p;
}

/*
this will generate wrong sequence of powers of p
it is easy to see that the following sequence will be printed:
p^1, p^2, p^4, p^8, p^16, ...
but this is not what we wanted.
*/

// good

int p = 2;
int copy_p = p;
while(condition) {
    cout << p << endl;
    p *= copy_p;
}
