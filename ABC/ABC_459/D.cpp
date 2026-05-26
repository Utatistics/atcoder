#include <bits/stdc++.h>

using P = std::pair<int, char>;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        std::string S;
        std::cin >> S;

        int N = S.size();
        std::map<char, int> m;
        for (int i = 0; i < N; i++) m[S[i]]++;

        std::priority_queue<
            P,
            std::vector<P>,
            std::less<P>> pq; // max heap
        for (auto [k, v] : m) pq.push({v, k}); // k = char, v = cnt
        
        std::string ans = "No"; // feasibility check
        int t = pq.top().first;
        // std::cout << "N=" << N << ", t=" << t << std::endl; * debug
        if (N % 2 == 0 && t * 2 <= N) ans = "Yes";
        if (N % 2 != 0 && t * 2 <= N + 1) ans = "Yes";
        std::cout << ans << std::endl;
        if (ans == "No") continue;

        std::string s = "";
        char prev = '.';
        while (!pq.empty()) {
            P x = pq.top(); pq.pop();
            if (x.second == prev) { // x cannot be used
                P y = pq.top(); pq.pop(); // get y, pop y
                pq.push(x); // push x back
                x = y; // y is now x
            }
            s += x.second; prev = x.second;
            x.first--;
            if (x.first > 0) pq.push(x);
        }

        std::cout << s << "\n";
    }

    return 0;
}

