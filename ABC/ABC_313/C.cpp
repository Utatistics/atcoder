#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input
    int N;
    std::cin >> N;

    std::multiset<int> s;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        s.insert(a);
    }

    // solve

    ll ans = 0;
    bool status = false;
    while (!status && N > 1) {
        int min = *s.begin();
        int max = *s.rbegin();
        if (max - min == 1) {
            status = true;
            continue;
        }
       
        int a = min;
        int b = max;
        while (max - min > 1) {
            max--;
            min++;
            ans++;
        }
        // O(log N)
        s.erase(a);
        s.erase(b);
        s.insert(min);
        s.insert(max);
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}

