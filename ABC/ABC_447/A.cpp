#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    if (N % 2 == 0) {
        if (M <= N / 2) std::cout <<"Yes\n";
        else std::cout << "No\n";
    }
    else {
        if (M <= N / 2 + 1) std::cout << "Yes\n";
        else std::cout << "No\n";
    }

    return 0;
}
