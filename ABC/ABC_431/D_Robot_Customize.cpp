#include<iostream>
#include<vector>

typedef struct parts { int w; int h; int b; } P;

int main () {
    int N;
    std::cin >> N;
    int W = 0;
    long long B = 0;
    std::vector<P> v;
    for (int i = 0; i < N; i++) {
        int w, h, b;
        std::cin >> w >> h >> b;
        W += w;
        B += b;
        v.push_back({w, h, b});
    }

    int M = W / 2;
    const long long INF = 1e18;
    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(M + 1, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        P p = v[i];
        for (int j = M; j >= 0; j--) {
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
            if (j + p.w <= M) dp[i + 1][j + p.w] = std::max(dp[i + 1][j + p.w], dp[i][j] + p.h - p.b);
        }
    }
    long long ans = -INF;
    for (int j = 0; j < M + 1; j++) ans = std::max(ans, dp[N][j]);
    std::cout << B + ans << "\n";
    
}

//w h  b
//1 41 59
//2 65 35
//8 97 93

//s/w: 0    1    2    3    4    5
//-------------------------------
// 0 | 0 -INF -INF -INF -INF -INF
// 1 | 0   41 -INF -INF -INF -INF
// 2 | 0   41   65  106 -INF -INF
// 3 | 0   41   65  106 _INF -INF
