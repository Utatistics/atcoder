#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> next(N + 1);
    for (int i = 1; i <= N; i++) {
        int a;
        std::cin >> a;

        if (a == -1) 
            next[0] = i;
        else 
            next[a] = i;
    }

    int k = next[0];
    for (int i = 0; i < N; i++) {
        std::cout << k << " ";
        k = next[k];
    }
    std::cout << '\n';
}
