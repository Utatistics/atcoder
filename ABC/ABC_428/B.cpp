#include <bits/stdc++.h>

int main() {
    // input
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;

    // solve
    int ans = 0;
    std::map<int, std::set<std::string>> m;
    for (int i = 0; i <= N - K; i++) {
        int x = 0;
        std::string t = S.substr(i, K);
        for (int  j = 0; j <= N - K; j++) {
            if (t == S.substr(j, K)) x++;
        }
        // evaluate
        m[x].insert(t); // auto sort
        ans = std::max(ans, x);
    }

    // presentaiton
    std::cout << ans << std::endl;
    for (auto t : m[ans]) std::cout << t << " ";
    std::cout << std::endl;

    return 0;
}

