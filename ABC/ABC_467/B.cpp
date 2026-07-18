#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int X = 10000;
    int Y = 10000;

 
    for (int i = 0; i < N; i++) {
        int a, b;
        std::string s;
        std::cin >> a >> b >> s;

        X -= (s == "take") ? a : b;
        Y -= a;
    }

    std::cout << Y - X << std::endl;

    return 0;
}

