#include <iostream>
#include <vector>
#include <algorithm>

int main () {
    // input processing
    int N; // 10^1
    std::cin >> N;
    std::vector<std::vector<int>> A(N, std::vector(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }
    int M;
    std::cin >> M;
    std::vector<std::vector<bool>> B(N, std::vector(N, false));
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
        B[x][y] = true; B[y][x] = true;
    }
    
    // factorial brute forces
    static const int INF = 1e3 * N + 1;
    int ans = INF;
    std::vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);
    do {        
        bool status = true; // init
        for (int i = 0; i < N; i++) {
            if(i != N - 1 && B[v[i]][v[i+1]] == true) status = false;
        }        
        if (!status) continue;
 
        int t = 0; // init
        for (int i = 0; i < N; i++) t += A[v[i]][i];
        ans = std::min(ans, t);
        
    } while (std::next_permutation(v.begin(), v.end())); // v modified in place

    if (ans != INF) std::cout << ans;
    else std::cout << -1;

    return 0;
}
