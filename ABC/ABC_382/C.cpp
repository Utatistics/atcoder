#include <bits/stdc++.h>

using P = std::pair<int, int>;

int binary_search(int key, const::std::vector<P> &A) {
    int left = -1; // i = 0 does not always satisfy condition
    int right = (int)A.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (A[mid].first <= key) right = mid; // argmin k (key < A[k]) *ascending
        else left = mid;
    }
    return right;
}

int main() {
    // input
    int N, M;
    std::cin >> N >> M;

    std::vector<P> A;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (i == 0) A.push_back({a, i});
        else {
            if (a < A.back().first) A.push_back({a, i});
        }
    } 
    std::vector<int> B(M);
    for (int i = 0; i < M; i++) std::cin >> B[i];

    // solve
    for (int b : B) {
        int ans = -1;
        int k = binary_search(b, A);

        // presentation
        if (k != (int)A.size()) ans = A[k].second + 1; // 0 to 1 index
        std::cout << ans << std::endl;
    }

    return 0;
}

