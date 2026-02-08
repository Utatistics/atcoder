#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

static const int INF = 1e9;

int main () {
    // input processing
    int N, Q;
    long long a, b;
    std::multiset<long long> msA;
    std::multiset<std::pair<long long, int>> msB; // {var, index}
    
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        msA.insert(a); // O(log N)
    }
    
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        std::cin >> b;
        msB.insert({b, i});
    }

    // solve
    long long d0, d1;
    d0 = d1 = INF;
    
    int j = 0;
    std::unordered_map<int, long long> ans;
    for (int i = 0; i < Q; i++) {
        auto b = *msB.begin();
        while (j < N) {
            auto it = msA.begin();
            for (int k = 0; k < j; k++) ++it;
            long long a = *(it);
            d1 = std::abs(a - b.first);
            if (j > 0 && d0 < d1) {
                ans[b.second] = d0;
                break;
            }
            else if (j + 1 == N) { // reached max depth
                ans[b.second] = d1;
                break;
            }
            else d0 = d1;
            j++;
            
        }
        msB.erase(msB.begin());
        j = 0;
    }
    
    for (int i = 0; i < Q; i++) std::cout << ans[i] << "\n";
    return 0;
}

