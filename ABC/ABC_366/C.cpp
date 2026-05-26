#include <bits/stdc++.h>

int main() {
    int Q;
    std::cin >> Q;

    int ans = 0;
    std::map<int, int> cnt;
    
    while (Q--) {
        int t;
        std::cin >> t;
     
        if (t == 1) { // add
            int x;
            std::cin >> x;
            if (cnt[x] == 0) ans++;
            cnt[x]++;
        }
        else if (t == 2) { // remove
            int x;
            std::cin >> x;
            if (cnt[x] == 1) ans--;
            cnt[x]--;
        }
        else {
            std::cout << ans << "\n";
        }
    }
    return 0;
}

