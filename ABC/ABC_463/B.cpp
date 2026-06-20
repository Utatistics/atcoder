#include <bits/stdc++.h>

int main() {
    int N;
    char X;
    std::cin >> N >> X;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];

    auto f = [&](char c) -> int {
        if (c =='A') return 0;
        else if (c =='B') return 1;
        else if (c =='C') return 2;
        else if (c =='D') return 3;
        else return 4;
    };

    std::string ans = "No";
    for (std::string x : S) {
        if (x[f(X)] == 'o') {
            ans = "Yes";
            break;
        }
    }

    std::cout << ans << std::endl;
   
    return 0;
}

