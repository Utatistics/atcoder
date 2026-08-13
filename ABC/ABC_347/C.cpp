#include <bits/stdc++.h>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<int> D(N);
    for (int i = 0; i < N; i++) {
        int d;
        std::cin >> d;
        D[i] = d % (A + B);
    }
    std::sort(D.begin(), D.end());

    std::string ans = "No\n";
    for (int i = 0; i < N; i++) {
        int d = -1;
        if (i == N - 1) 
            d = D[0] + A + B - D[i];
        else 
            d = D[i + 1] - D[i];

        if (d > B) ans = "Yes\n";
    }

    std::cout << ans;
    return 0;
}

