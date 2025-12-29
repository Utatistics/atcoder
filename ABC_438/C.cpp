#include <iostream>
#include <utility>
#include <vector>
#include <stack>

void debug(std::stack<std::pair<int, int>> &s) {
    while (!s.empty()) {
        std::pair<int, int> p = s.top();
        std::cout << "{" << p.first << "," << p.second << "}" << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main () {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    // solve
    std::stack<std::pair<int, int>> S; 
    S.push({A[0], 1}); // init

    for (int i = 1; i < N; i++) {
        int a = A[i];
        std::cout << "i=" << i << ", a=" << a << std::endl;
        debug(S);
        std::pair<int, int> p = S.top(); // {value, cnt}

        if (a != p.first) {
            std::pair<int, int> q = {a, 1}; 
            S.push(q);
            
        }
        else if (a == p.first && p.second + 1 < 4) {
            p.second += 1;
            S.pop();
            S.push(p);
            std::pair<int, int> q = {a, 1};
            S.push(q);
        }
        else if (a == p.first && p.second == 4) S.pop();
    }

    // presentation
    int ans = 0;
    while (!S.empty()) {
        std::pair<int, int> p = S.top();
        ans += p.second;
        S.pop();
    }
    std::cout << ans << std::endl;

}

