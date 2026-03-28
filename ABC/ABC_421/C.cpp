#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    // solve
    std::vector<int> A;
    for (int i = 0; i < 2 * N; i++)
        if (S[i] == 'A') A.push_back(i);
    
    ll a = 0;
    ll b = 0;
    for (int i = 0; i < N; i++) {
        a += std::abs(A[i] - 2 * i);
        b += std::abs(A[i] - ((2 * i) + 1));
    }

    // presentation
    std::cout << std::min(a, b) << std::endl;

    return 0;
}

