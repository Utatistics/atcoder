#include <iostream>
#include <utility>
#include <vector>
#include <stack>

void debug(std::stack<std::pair<int, int>> s) { // pass by value
    std::cout << "->";
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
    
    // debug
    // std::cout << "i=" << 0 << ", a=" << A[0] << std::endl;
    // debug(S);
    
    for (int i = 1; i < N; i++) {
        int a = A[i];
        std::pair<int, int> p;
        // std::cout << "i=" << i << ", a=" << a << std::endl; // debug
        if (!S.empty()) p = S.top(); // {value, cnt}
        else {
            S.push({a, 1});
            continue;
        }

        if (a != p.first) {
            std::pair<int, int> q = {a, 1}; 
            S.push(q);    
        }
        else if (a == p.first && p.second + 1 < 4) {
            p.second += 1;
            if (!S.empty()) S.pop();
            S.push(p);
        }
        else if (a == p.first && p.second + 1 == 4) {
            if (!S.empty()) S.pop();
        }
        
        // debug(S);
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
