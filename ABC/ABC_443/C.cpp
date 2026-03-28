#include <bits/stdc++.h>

int main() {
    // input processing
    int N, T;
    std::cin >> N >> T;

    std::queue<int> q;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        q.push(a);

        if (i == N - 1 && a != T) q.push(T);
    }

    // solve
    std::vector<std::pair<int, int>> online;
   
    int t = 0;
    if (N > 0) { // init
        int a = q.front();
        online.push_back({t, a});
        t = a;
        q.pop();
    }

    while (!q.empty()) {
        int a = q.front();
        if (t + 100 < a) {
            online.push_back({t + 100, a});
            t = a;
        }
        q.pop();
    }

    // presentation
    int ans = (N > 0) ? 0 : T;
    for (auto p : online) ans += (p.second - p.first);
    std::cout << ans << std::endl;

    return 0;
}

