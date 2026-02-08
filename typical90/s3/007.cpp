#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(int key, const std::vector<int> &A) {
    int l = -1;
    int u = (int)A.size();
    while (u - l > 1) {
        int m = (l + u) / 2;
        if (key <= A[m]) u = m;
        else l = m;
    }
    long long d0 = std::abs(key - A[u]);
    long long d1 = std::abs(key - A[u - 1]);
    if (key < A[0]) return A[0] - key; // edge case
    else return std::min(d0, d1);
}

int main () {
    int N, Q;
    long long a, b;
    std::vector<int> A, B;

    // input processing
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        A.push_back(a);
    }
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        std::cin >> b;
        B.push_back(b);
    }

    // solve
    std::sort(A.begin(), A.end(), [](int a, int b){return a < b;}); // O(NlogN)
    for (int i = 0; i < Q; i++) {
        long long b = B[i];
        int ans = binarySearch(b, A); // O(logN)
        std::cout << ans << std::endl;
    }

    return 0;
}
