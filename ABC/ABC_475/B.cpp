#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; i++) {
        int x = (1000 - (A[i] % 1000)) % 1000;

        if (x >= 100) {
            a += x / 100;
            x = x % 100;
        }
        if (x >= 10) {
            b += x / 10;
            x = x % 10;
        }
        if (x >= 1) {
            c += x;
        }
    }

    std::cout << c << " " << b << " " << a << std::endl;
    return 0;
}
