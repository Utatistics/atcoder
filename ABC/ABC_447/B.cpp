#include <bits/stdc++.h>

using P = std::pair<int, char>;

int main() {
    // input
    std::string S;
    std::cin >> S;

    std::map<char , int> m;
    for (char c : S) m[c]++;

    std::priority_queue<P, std::vector<P>, std::less<P>> pq;
    for (auto [c, cnt] : m) pq.push({cnt, c});

    std::set<char> ans;
    auto p = pq.top();
    int M = p.first;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first == M) ans.insert(p.second);
        else break;
    }

    // presentation
    if (M == 1) std::cout << "\n";
    else {
        for (char c : S) if (!ans.count(c)) std::cout << c;
        std::cout << std::endl;
    }

    return 0;
}
