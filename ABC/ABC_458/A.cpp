#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;
    int N;
    std::cin >> N;


    std::string ans = "";
    int M = S.size();
    for (int i = N; i < M - N; i++) ans += S[i];

    std::cout << ans <<std::endl;
    return 0;
}
