#include <iostream>
#include <vector>

inline int max(int a, int b) {return (a < b) ? b : a;}
template <class T> using matrix = std::vector<std::vector<T>>;
int N, W; // number of objects, total weight // <10000, <10000
std::vector<int> v, w; // values, weights
matrix<int> memo(10000, std::vector<int>(10000, 0)); // init 0 // ~100MB // Ok

int main()
{
    std::cin >> N >> W;
    v.resize(N); w.resize(N);
    for(int i = 0; i < N; i++) {
        std::cin >> v[i] >> w[i];
    }

    // bottom up approach // no stack concern
    for(int j = 0; j <= W; j++) { // initializing first row of memo
        if(j >= w[0]) memo[0][j] = v[0];
    }

    // O(N * W) psudopolynomial
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j <= W; ++j) {
            if(j < w[i]) memo[i][j] = memo[i-1][j];
            else memo[i][j] = max(memo[i-1][j], v[i] + memo[i-1][j-w[i]]);
        }
    }

    std::cout << memo[N-1][W] << std::endl;
}
