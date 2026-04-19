#include <iostream>
#include <string>
#include <queue>
#include <vector>

int main() {
    std::string X;
    std::cin >> X;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    int cnt = 0; // zeros
    for (char c : X) {
        if (c == '0') cnt++;
        else pq.push(c - '0');
    }

    std::cout << pq.top(); pq.pop();
    for (int i = 0; i < cnt; i++) std::cout << '0';
    while (!pq.empty()) {
        std::cout << pq.top(); pq.pop();
    }

    return 0;
}

