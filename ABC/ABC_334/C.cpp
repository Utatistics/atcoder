#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;
    int M = 2 * N - K;

    std::vector<int> A(N + 1, 0); // lock sock
    for (int i = 0; i < K; i++) {
        int a;
        std::cin >> a;
        A[a]++;
    }

    std::vector<int> v;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
        if (A[i] == 0)
            v.push_back(i);
    }

    long long ans = 0;
    if (M % 2 == 0) {
        for (int i = 0; i < M / 2; i++)
            ans += v[2 * i + 1] - v[2 * i];
    }
    else {
        for (int i = 1; i <= M / 2; i++)
            ans += v[2 * i] - v[2 * i - 1];

        long long b = ans;
        for (int i = 1; i <= M / 2; i++) {
            b += v[2 * i - 1] - v[2 * i - 2];
            b -= v[2 * i + 1] - v[2 * i];
            ans = std::min(ans, b);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
