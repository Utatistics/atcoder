#include <bits/stdc++.h>

using ll = long long;
using P = std::pair<int, int>;

int main() {
    int N, K, M;
    std::cin >> N >> K >> M;

    std::vector<P> A(N);
    for (int i = 0; i < N; i++) {
        int c, v;
        std::cin >> c >> v;
        A[i] = {v, c};
    }
    auto f = [](P a, P b){
        if (a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
    };
    std::sort(A.begin(), A.end(), f); // O(N * logN)
    
    ll ans = 0;
    
    int k = 0;
    int m = 0;
    std::unordered_set<int> s;
    for (int i = 0; i < N; i++) {
        P p = A[i];
        if (s.count(p.second) == 0) {
            m++;
            s.insert(p.second);
        };

        if (K - k > M - m) {
            k++;
            ans += p.first;
        }
        
        if (k == K) break;
    }

    std::cout << ans << std::endl;
    return 0;
}

