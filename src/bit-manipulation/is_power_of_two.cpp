// template version
template <class Int>
bool is_power_of_two(Int n) {
    return (n && !(n & (n - 1)));
}

// int version
bool is_power_of_two(int n) {
    return (n && !(n & (n - 1)));
}
