#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N;
    std::cin >> N;

    std::vector<P> A;
    for (int i = 0; i < N; i++) {
        int f, s;
        std::cin >> f >> s;
        A.emplace_back(s, f);
    }
    std::sort(A.rbegin(), A.rend());

    int ans0 = A[0].first;
    for (int i = 1; i < N; i++) {
        if (A[i].second == A[0].second) {
            ans0 += A[i].first / 2;
            break;
        }

    }
    int ans1 = A[0].first;
    for (int i = 1; i < N; i++) {
        if (A[i].second != A[0].second) {
            ans1 += A[i].first;
            break;
        }
    }

    std::cout << std::max(ans0, ans1) << std::endl;
    return 0;
}

