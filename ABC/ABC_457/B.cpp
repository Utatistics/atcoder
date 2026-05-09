#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        for (int j = 0; j < L; j++) {
            int a;
            std::cin >> a;
            A[i].push_back(a);
        }
    }

    int X, Y;
    std::cin >> X >> Y;
    X--; Y--;
    std::cout << A[X][Y] << std::endl;

    return 0;
}

