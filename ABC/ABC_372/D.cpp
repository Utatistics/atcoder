#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> H(N);
    for (int i = 0; i < N; i++) std::cin >> H[i];

    std::vector<int> ans;
    ans.push_back(0); // init

    std::stack<int> s;
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty()) {
            int x = s.top();
            if (x < H[i]) s.pop();
            else break;
        }

        s.push(H[i]);
        int cnt = s.size();
        ans.push_back(cnt);
    }

    for (int i = N - 1; i >= 0; i--) std::cout << ans[i] << " ";
    std::cout << std::endl;

    return 0;
}

