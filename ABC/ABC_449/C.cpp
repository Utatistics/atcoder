#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input
    int N, L, R;
    std::cin >> N >> L >> R;

    std::string S;
    std::cin >> S;

    // solve
    ll ans = 0;
    std::unordered_map<char, int> m;   // char counter map   

    // init (cap at N-1)
    for (int i = L; i <= R; i++) m[S[i]]++;
    for (int i = 0; i < N; i++) {
        ans += m[S[i]];

        // slide window
        if (i + 1 + R < N) m[S[i + R + 1]]++;
        if (i + L < N) m[S[i + L]]--;
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}
