/* Disclaimer: This code dates back to 2018 and is not properly tested. */
#include <iostream>

#include <algorithm>
using namespace std;

template <class T>
static void max_heapify(T* arr, size_t n, size_t i) {
    size_t change_idx = i;
    if(2 * i <= n && arr[i] < arr[2 * i]) change_idx = 2 * i;
    if(2 * i + 1 <= n && arr[i] < arr[2 * i + 1] && arr[2 * i] < arr[2 * i + 1]) change_idx = 2 * i + 1;
    std::swap(arr[i], arr[change_idx]);
    if(change_idx != i) max_heapify(arr, n, change_idx);
}

template <class T>
static void build_max_heap(T* arr, size_t n, size_t i) {
    if(i > n) return ;
    build_max_heap(arr, n, 2 * i);
    build_max_heap(arr, n, 2 * i + 1);
    max_heapify(arr, n, i);
}

template <class T>
void heap_sort(T* arr, size_t n)
{
    build_max_heap(arr, n, 1);
    for(int i = n; i > 1; i--) {
        std::swap(arr[i], arr[1]);
        max_heapify(arr, i - 1, 1);
    }
}

// Usage example:
/*
int a[10000];
int main()
{
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) std::cin >> a[i];

    heap_sort<int>(a, n);
    for(int i = 1; i <= n; i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}
*/
