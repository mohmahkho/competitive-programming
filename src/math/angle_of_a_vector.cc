constexpr double PI = atan(1) * 4;

inline double ang(int x, int y) {
    double ret = atan2((double) y, (double) x);
    if(ret < 0) ret += 2 * PI;
    return ret;
}
