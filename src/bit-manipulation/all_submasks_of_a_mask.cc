// you have mask msk
    for(int s = msk; s; s = (s - 1) & msk) {
        // s is submask of msk
    }
// with 0 as submask
    for(int s = msk; ; s = (s - 1) & msk) {
        // s is submask of msk
        if(s == 0) break;
    }
