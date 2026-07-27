#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> P(N, -1);
    for (int i = 0; i < N; i++) {
        int p;
        std::cin >> p;
        --p;
        P[p] = i;
    }
    
    int ans = N;
    
    std::set<int> s;
    int r = 0; // right ptr
    for (int l = 0; l + K <= N; l++) { // left ptr
        while (r < N && r - l < K) { // monotonically increasing
            s.insert(P[r]);
            r++;
        }
        
        int mini = *s.begin();
        int maxi = *s.rbegin();
        ans = std::min(ans, maxi - mini);

        s.erase(P[l]); // prepare 'l' to move forward
    }
    
    std::cout << ans << std::endl;
    return 0;
}

