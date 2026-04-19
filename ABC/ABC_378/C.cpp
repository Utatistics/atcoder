#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> B(N);
    std::map<int, std::queue<int>> mq;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        int b;
        if (mq[a].empty()) {
            b = -1;
        }
        else {
            b = mq[a].front(); mq[a].pop();
        }
        mq[a].push(i + 1);
        B[i] = b;
    }

    for (int i = 0; i < N; i++)
        std::cout << B[i] << std::endl;

    return 0;
}

