#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    // solve
    // std::map<int, int> m; not needed
    std::vector<int> c(N, 0); // count vector
    for (int x = 1; x * x < N; x++) {
        for (int y = x + 1; x*x + y*y <=N; y++) {
            c[(x*x + y*y) - 1]++;
        }
    }
 
    int cnt = 0;
    std::vector<int> ans; // extract good ones
    for (int i = 0; i < N; i++) {
        if (c[i] == 1) {
            ans.push_back(i + 1);
            cnt += 1;
        }
    }
    
    // presentation
    std::cout << cnt << std::endl;
    for (int a : ans) std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

