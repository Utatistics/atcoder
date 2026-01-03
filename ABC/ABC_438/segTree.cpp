#include <bits/stdc++.h>

struct segTree { // RMQ (range maximam query)
    int N = 1;
    int d = 0; // depth
    int k; // the first leaf index
    std::vector<long long> t; // tree 

    segTree(const std::vector<long long> &x) {
        // init
        int s = (int)x.size();
        while (N <= 2 * s) {
            N <<= 1;
            d++;
        }
        t.assign(N - 1, -INF); // 0 index
        k = (1 << (d - 1)) - 1; // the first leaf index

        // build leaves {2^(d-1) - 1, ..., N - 1}
        // std::cout << "leaves...\n";
        for (int i = 0; i < s; i++) {
            // std::cout << "-->i=" << i;
            t[i + k] = x[i];
            // std::cout << ", k=" << k << ", i+k=" << i+k << ", t=" << t[i + k] << std::endl;
        }
       
        // build internal nodes {0, ... 2^(d-1) - 2}
        // std::cout << "internal node...\n";
        for (int i = k - 1; i >= 0; i--) {
            // std::cout << "-->i=" << i;
            t[i] = std::max(t[2 * i + 1] , t[2 * i + 2]);
            // std::cout << ", t=" << t[i] << std::endl;
        }
    }

    long long queryMax(int l, int r) { // [l, r), O(log N)
        long long res = -INF;
        for (l += k, r += k; l < r; l = (l - 1) / 2, r = (r - 1) / 2) {
            if ((l & 1) == 0) res = std::max(res, t[l++]);
            if ((r & 1) == 0) res = std::max(res, t[--r]);
        }
        return res;
    }

    // void update(int i, int v) {
    
    void show () const { // debug
        int p = 0; // level
        int cnt = 1 << p; // i.e. 2^p = 1, number of elements at the level
        for (int i = 0; i < N - 1; i++) {
            std::cout << t[i] << " ";
            if (i + 1 == cnt) { // level up next?
                std::cout << std::endl;
                p++;
                cnt += 1 << p;
            }
        }
        std::cout << std::endl;
    }

};
