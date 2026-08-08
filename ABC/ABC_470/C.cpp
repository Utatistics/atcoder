#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    int ans = 0; // xor cumurative
    std::vector<int> A(N, 0);
    std::vector<int> B; // above 0 club

    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) { // O(1)
            int x;
            std::cin >> x;
            --x;

            ans ^= A[x] ^ (A[x] + 1); // cancel the previous and then update with +1
            
            if (A[x] == 0) B.push_back(x);
            ++A[x];
        }
        else { // amortized complexity 
            for (auto x : B) {
                ans ^= A[x] ^ (A[x] - 1);
                --A[x];
            }

            std::vector<int> tmp;
            for (auto x : B) { // rebuild with move
                if (A[x] > 0) tmp.push_back(x);
            }
            B = std::move(tmp);
        }
        std::cout << ans << "\n";
    }

    return 0;
}

