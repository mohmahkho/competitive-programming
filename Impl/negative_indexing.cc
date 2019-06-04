#include <bits/stdc++.h>
using namespace std;

int constexpr N = 100009 * 2;
int a_ptr[N], *a = a_ptr + N / 2;

int main() {
    for(int i = -199; i < 1000; ++i) {
        a[i] = i * i * i;
    }
}

/*
we take a pointer to the array but we place the pointer at the middle of the array
so that we can index before and after the pointer!
*/
