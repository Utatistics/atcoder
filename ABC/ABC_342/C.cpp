#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int Q;
    std::cin >> Q;

    std::vector<char> m(26);
    for (int i = 0; i < 26; i++) {
        m[i] = 'a' + i;
    }

    while (Q--) {
        char c, d;
        std::cin >> c >> d;

        for (int i = 0; i < 26; i++) {
            if (m[i] == c) {
                m[i] = d;
            }
        }
    }

    for (char c : S) 
        std::cout << m[c - 'a'];
    std::cout << '\n';

    return 0;
}
