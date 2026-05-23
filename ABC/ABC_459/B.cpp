#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) std::cin >> S[i];

    std::string ans = "";
    for (int i = 0; i < N; i++) {
        char ci;
        char c = S[i][0];

        if (c == 'a' || c == 'b' || c == 'c') ci = '2';
        else if (c == 'd' || c == 'e' || c == 'f') ci = '3';
        else if (c == 'g' || c == 'h' || c == 'i') ci = '4';
        else if (c == 'j' || c == 'k' || c == 'l') ci = '5';
        else if (c == 'm' || c == 'n' || c == 'o') ci = '6';
        else if (c == 'p' || c == 'q' || c == 'r' || c == 's') ci = '7';
        else if (c == 't' || c == 'u' || c == 'v') ci = '8';
        else ci = '9';

        ans += ci;
    }
    std::cout << ans << std::endl;

    return 0;
}

