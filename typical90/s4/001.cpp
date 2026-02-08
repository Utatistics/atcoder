#include<iostream>
#include<vector>

int solve(int m, const int &N, std::vector<int> &Y) {
   int y = 0; int cnt = -1;
    for (int i = 0; i < N + 1; i++) {
        if (Y[i] - y >= m) {
            cnt++;
            y = Y[i];
        };
    }
    return cnt;
}

int main () {
    int N, L, K;
    std::cin >> N >> L >> K;
    std::vector<int> Y(N + 1, L);
    for (int i = 0; i < N; i++) {
        int y;
        std::cin >> y;
        Y[i] = y;
    }
    
    int l = -1; int r = L + 1; // binary search
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (solve(m, N, Y) < K) r = m;
        else l = m;
    }
    
    int ans = l;
    std::cout << ans << std::endl;

    return 0;
}

