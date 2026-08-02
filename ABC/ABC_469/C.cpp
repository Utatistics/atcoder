#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> b(N + 1, 0);
    for (int i = 1; i <= N; i++)
        b[i] = b[i - 1] + (S[i - 1] == 'x');

    int r = 1;
    for (int k = 1; k <= N; k++) {
        if (r < k)
            r = k;

        while (r <= N && b[r] < k)
            r++;

        if (r <= N)
            std::cout << r << "\n";
        else
            std::cout << N << "\n";
    }

    return 0;
}
