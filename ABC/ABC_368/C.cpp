#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::queue<int> q;
    for (int i = 0; i < N; i++) {
        int h;
        std::cin >> h;
        q.push(h);
    }

    ll T = 0;
    while (!q.empty()) {
        int h = q.front();
        T += (h / 5) * 3; // floor 5
        
        int r = h % 5; // remiander
        while (r > 0) {
            T++;
            if (T % 3 == 0) r -= 3;
            else r -= 1;
        }
        q.pop();
    }

    std::cout << T << std::endl;
    return 0;
}

