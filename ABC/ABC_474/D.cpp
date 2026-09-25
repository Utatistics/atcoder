#include <bits/stdc++.h>

using ll = long long;
static const ll MAX = 1000000000000000000LL;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];

    bool ans = false;
    for (int i = 0; i < N; i++) if (A[i] > B[i]) ans = true;

    if (!ans) {
        std::cout << "No\n";
        return 0;
    }

    std::cout << "Yes\n";
    for (int i = 0; i < N; i++) {
        std::cout << (A[i] > B[i] ? MAX : 1) << (i + 1 == N ? '\n' : ' ');
    }

    return 0;
}
