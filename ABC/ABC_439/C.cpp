#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    // solve
    std::map<int, int> m;
    for (int x = 1; x * x < N; x++) {
        for (int y = x + 1; x*x + y*y <= N; y++) {
            m[x*x + y*y]++;
        }
    }

    int cnt = 0;
    std::vector<int> ans;
    for (int n = 1; n <= N; n++) {
        for (const auto&[v, c] : m) {
            if (v == n && c == 1) {
                ans.push_back(v);
                cnt++;
            }
        }
    }

    // presentation
    std::cout << cnt << std::endl;
    for (int  i = 0; i < cnt; i++) std::cout << ans[i] << " ";
    std::cout << std::endl;
        
    
    return 0;
}

