#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> H(N);
    for (int i = 0; i < N; i++) std::cin >> H[i];

    // solve
    int ans = 1;
    for (int i = 0; i < N; i++) { // start
        for (int j = 1; j < N; j++) { // width
            int l = i;
            int r = i + j;
            int cnt = 0;
            while (r < N && H[l] == H[i] && H[r] == H[i]) {
                cnt++;
                l = r;
                r = l + j; // slide window
            }
            ans = std::max(ans, cnt + 1);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
