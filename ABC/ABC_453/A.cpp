#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for (char c : S) {
        if (c == 'o') cnt++;
        else break;
    }

    
    for (int i = cnt; i < N; i++) std::cout << S[i];
    std::cout << std::endl;

    return 0;
}

