#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<P> A(N);
    for (int i = 0; i < N; i++) {
        int h, l;
        std::cin >> h >> l;
        A[i] = {h, l};
    }
    std::sort(A.begin(), A.end());
    
    std::vector<P> B;
    int ml = 0;
    for (int i = N - 1; i >= 0; i--) {
        auto[h, l] = A[i];
        if (l <= ml) continue;
        B.push_back({l, h});
        ml = l;
    }

    auto binarySearch = [&](int key) -> int {
        int left = -1; // i = 0 does not always satisfy condition
        int right = (int)B.size();
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (B[mid].first > key) right = mid;
            else left = mid;
        }
        return B[right].second; // (int)A.size() if not found. 

    };

    int Q;
    std::cin >> Q;
    while (Q--) {
        int t;
        std::cin >> t;

        int ans = binarySearch(t);
        std::cout << ans << std::endl;
    }

    return 0;
}

