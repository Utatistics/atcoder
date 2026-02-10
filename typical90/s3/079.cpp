#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int H, W;
    std::cin >> H >> W;

    std::vector<int> A(H * W);
    for (int i = 0; i < H; i++) { // H for rownum
        for (int j = 0; j < W; j++) { // W for colnum
            std::cin >> A[j + i * W];
        }
    }
    std::vector<int> B(H * W);
    for (int i = 0; i < H; i++) { // H for rownum
        for (int j = 0; j < W; j++) { // W for colnum
            std::cin >> B[j + i * W];
        }
    }

    // solve
    ll ans = 0;
    for (int i = 0; i < H * W; i++) {
        int j = i + 1;
        int k = i + W;
        int l = i + W + 1;
        ll d = B[i] - A[i];
 
        if (i % W == W - 1) { // last column
            if (d != 0) { std::cout << "No\n"; return 0; }
            continue;
        }
        else if (i >= W * (H - 1)) { // last row
            if (d != 0) { std::cout << "No\n"; return 0; }
            continue;
        }
            else {
            A[j] += d;
            A[k] += d;
            A[l] += d;
            ans += std::llabs(d);
        }
    }

    // presentation
    std::cout << "Yes\n" << ans << std::endl;
    
    return 0;
}

