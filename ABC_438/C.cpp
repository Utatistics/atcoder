#include <iostream>
#include <utility>
#include <vector>
#include <stack>

int main () {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A;
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    // solve
    std::stack<std::pair<int, int>> S; 
    S.push({A[0], 1}); // init

    for (int i = 1; i < N; i++) {
        std::pair<int, int> p = S.top(); // {value, cnt}
        int a = A[i];

        if (a == p.first) p.second += 1;
        else std::pair<int, int> q = {a, 1};

        if (p.second == 4) S.pop();
        else S.push(p);
        
        S.push(q);
    }

    // presentation
    int ans = 0;
    while (!S.empty()) {
        std::pair<int, int> p = S.top();
        ans += p.second;
        S.pop();
    }
    std::cout << ans;

}

