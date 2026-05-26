#include <bits/stdc++.h>

using P = std::pair<char, int>;

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::string S;
        std::cin >> S;

        std::vector<P> rle;
        char prev = S[0];
        int cnt = 0;
        for (int i = 0; i < N; i++) { // RLE
            if (S[i] == prev) cnt++;
            else {
                rle.push_back({prev, cnt});
                cnt = 1;
            }
            prev = S[i];
        }
        rle.push_back({prev, cnt}); // last seq
        int n = rle.size();

        std::vector<int> c0(n + 1, 0);
        std::vector<int> c1(n + 1, 0);
        
        int k = 1;
        int l0 = 0; // max length for 0
        int l1 = 0; // max length for 1
        int k0 = 0; // argmax for 0
        int k1 = 0; // argmax for 1

        for (auto p : rle) {
            if (p.first == '0') {
                c0[k] = c0[k - 1] + p.second;
                c1[k] = c1[k - 1];
                l0 = std::max(l0, p.second);
                if (l0 == p.second) k0 = k;
            }
            else {
                c1[k] = c1[k - 1] + p.second;
                c0[k] = c0[k - 1];
                l1 = std::max(l1, p.second);
                if (l1 == p.second) k1 = k;
            }
            k++;
        }

        int ans0 = 2 * (c0[k0 - 1] + c0[n] - c0[k0]) + (c1[k0 - 1] + c1[n] - c1[k0]);
        int ans1 = 2 * (c1[k1 - 1] + c1[n] - c1[k1]) + (c0[k1 - 1] + c0[n] - c0[k1]);

        std::cout << std::min(ans0, ans1) << "\n";
    }
    return 0;
}

