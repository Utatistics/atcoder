#include <bits/stdc++.h>

using ll = long long;

int binary_search(int i, int key, const::std::vector<ll> &A) {
    int left = i - 1; // i = 0 does not always satisfy condition
    int right = (int)A.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (A[mid] - A[i + 1] >= key) right = mid; // argmin k (key < A[k]) *ascending
        else left = mid;
    }
    return right; // (int)A.size() if not found. 
}

int main() {
    // input processing
    int N, C;
    ll M;
    std::cin >> N >> M >> C;

    std::map<ll, int> m;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        m[a]++; m[a + M]++; // needs 2 times for val (not key)
    }
    int p;
    int n = m.size(); // O(N)

    p = 0;
    std::vector<ll> K; // key (point of start)
    for (auto [k, v] : m) {
        if (p > n / 2 - 1) {
            K.push_back(M);
            break;
        }
        K.push_back(k);
        p++;
    }
    
    p = 1;
    std::vector<ll> ps(n, 0);
    for (auto [k, v] : m) { // value (cnt as per each loc)
        ps[p] = ps[p - 1] + v;
        p++;
    }
    
    // solvne
    ll ans = 0;
    for (int i = 0; K[i] < M; i++) {
        int t = binary_search(i, C, ps); // get threshuold
        ll c = K[i + 1] - K[i]; // number of duplicates
        ans += (ps[t] - ps[i + 1]) * c;
    }
    
    // presentation
    std::cout << ans << std::endl;

    return 0;
}

std::vector<ll> enum_divisors(ll N) 

std::vector<ll> x;
for (ll i = 1; i * i <= N; ++i) { // O(√N)
    if (N % i == 0) {
        x.push_back(i);
        if (N / i != i) x.push_back(N / i); // avoid duplicates
    }
}
std::sort(x.begin(), x.end()); // if necessaryB 

