#include <bits/stdc++.h>

using ll = long long;
static const ll INF = 1e11 + 1;

struct segTree { // RMQ (range maximam query)
    int N = 1; // leaves size (i.e. tree size = 2 * N  - 1)
    std::vector<std::pair<ll, int>> t;

    segTree(const std::vector<ll>& x) {
        // init
        int s = x.size(); // array size
        while (N < s) N <<= 1;
        t.assign(2 * N - 1, {-INF, -1});
        
        // leaves
        // std::cout << "leaves...\n";
        for (int i = 0; i < s; i++) {
            // std::cout << "-->i=" << i <<", i+N-1=" << i+N-1 << ", x=" << x[i] << std::endl;
            t[i + N - 1] = {x[i], i};
        }
        
        // internal nodes
        // std::cout << "internal nodes...\n";
        for (int i = N - 2; i >= 0; i--) { // leaves start at N - 1 
            t[i] = max(t[2 * i + 1], t[2 * i + 2]);
            // std::cout << "-->i=" << i <<", t={" << t[i].first << ", " << t[i].second << "}" << std::endl;
        }
    }

    int queryMax(int l, int r) {  // [l, r) * hal-open
        l += N - 1; // move to leaves
        r += N - 2;  
        if (l == r) { // edge case
            while (1) { // walk overr
                if (l == 0) break;
                t[(l - 1) / 2] = t[l];
                l = (l - 1) / 2; // move up
            }
        } else { // normal
            while (l < r) { // update as per query
                // extracts LSB -> fight if 1(odd), else bye
                t[(l - 1) / 2] = ((l & 1) == 1) ? std::max(t[l], t[l + 1]) : t[l];
                t[(r - 1) / 2] = ((r & 1) == 0) ? std::max(t[r], t[r - 1]) : t[r];
                // std::cout << "-->l=" << l << ", r=" << r << std::endl;
                l = (l - 1) / 2; r = (r - 1) / 2; // move up 
            }         
        }
        return t[0].second; // argmax
    }
    
    void show () const { // for debug, tree forma
        std::cout << "showing the segTree...\n";
        int p = 0; // level
        int cnt = 1 << p; // i.e. 2^p = 1, number of elements at the level
        for (int i = 0; i < 2 * N - 1; i++) {
            std::cout << "{" << t[i].first << ", " << t[i].second << "} ";
            if (i + 1 == cnt) { // level up next?
                std::cout << std::endl;
                p++;
                cnt += 1 << p;
            }
        }
        std::cout << "\n";
    }
};

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<ll> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) std::cin >> A[i], A[i] += i ? A[i-1] : 0;
    for (int i = 0; i < N; i++) std::cin >> B[i], B[i] += i ? B[i-1] : 0;
    for (int i = 0; i < N; i++) std::cin >> C[i], C[i] += i ? C[i-1] : 0;
    for (int i = 0; i < N; i++) D[i] = B[i] - C[i];

    // solve
    struct segTree st(D);
    
    // debug
    st.show(); 
    ll ans = 0;
    for (int i = 0; i < N - 2; i++) {
        std::cout << "queryMax[" << i + 1 << ", " << N - 1 << ")\n";
        int j = st.queryMax(i + 1, N - 1);
        ans = std::max(ans, A[i] + (B[j] - B[i]) + (C[N - 1] - C[j])); 
        // debug 
        std::cout << "i=" << i << ", j=" << j << "-->" << A[i] + (B[j] - B[i]) + (C[N - 1] - C[j]) << "\n";
        st.show();
    }
    std::cout << ans << std::endl;
    return 0;
}

