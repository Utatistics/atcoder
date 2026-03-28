#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N, Y;
    std::cin >> N >> Y;

    int x, y, z;
    bool status = false;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (N < i + j) continue; // invalid x, y

            ll r = Y - (10000LL * i + 5000LL * j);
            if (r < 0) continue; // invalid x, y
            if (i + j + (r / 1000LL) == N) {
                status = true;
                x = i;
                y = j;
                break;
            }
        if (status) break;
        }
    }

    // presentation
    if (!status) std::cout << -1 << " " << -1 << " " << -1 << std::endl;
    else {
        z = N - (x + y);
        std::cout << x << " " << y << " " << z << std::endl;
    }
    return 0;
}

