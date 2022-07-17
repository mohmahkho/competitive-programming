int bezout(int a, int b, int &x, int &y) {
    int xold = 1, yold = 0;
    x = 0, y = 1;
    int ac = a, bc = b;
    while(a % b) {
        int r = a % b;
        int q = a / b;
        a = b;
        b = r;

        int xnew = xold - q * x;
        int ynew = yold - q * y;

        xold = x;
        yold = y;
        x = xnew;
        y = ynew;
    }
    return b; // b is gcd
}
