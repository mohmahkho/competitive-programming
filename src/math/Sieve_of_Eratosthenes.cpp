int constexpr MAXA = 15000001;
int lpf[MAXA];

void fill_lpf() {
    for(int i = 2; i < MAXA; i++) {
        if(lpf[i] == 0) {
            for(int j = i; j < MAXA; j += i) if(lpf[j] == 0) lpf[j] = i;
        }
    }
}
