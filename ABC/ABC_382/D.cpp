#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;

    int ans = 0;
    std::set<std::vector<int>> s;
   
    for (int i = 1; i < M; i++) {
        std::vector<int> A;
        A.push_back(i); // init 
         
        auto dfs = [&](auto f) -> void {
            if ((int)A.size() == N) {
                ++ans;
                s.insert(A);
                return;
            }

            for (int r = 10; r < M; r++) {
                int a = A.back() + r;
                int c = N - (int)A.size() - 1;
                if (a + c * 10 > M) return;
                
                A.push_back(a);
                f(f);
                A.pop_back(); // revert
            }
        };
        
        dfs(dfs);
    
    }
    
    std::cout << ans << std::endl;
    for (auto v : s) {
        for (int i = 0; i < N; i++) 
            std::cout << v[i] << " ";
        std::cout << "\n";
    }

    return 0;
}

