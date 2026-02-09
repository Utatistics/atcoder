#include <bits/stdc++.h>

using ll = long long;

bool binary_search(ll key, const std::vector<ll>& ps, int l) {
    int N = (int)ps.size() / 2;
    int left = l - 1;       // left always INVALID
    int right = l + N;      // right always VALID
    
    ll base = (l == 0 ? 0 : ps[l - 1]);
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        ll val = ps[mid] - base;

        if (val == key) return true;
        else if (val >= key) right = mid; // keep mid
        else left = mid; // eliminate mid
    }
    return false;
}

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(2 * N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A[i] = a;
        A[i + N] = a;
    }

    // solve
    std::vector<ll> ps(2 * N);
    for (int i = 0; i < 2 * N; i++)
        ps[i] = (i == 0) ? A[i] : ps[i - 1] + A[i];

    ll k = ps[N - 1] / 10LL;
    bool status = false;
    for (int i = 0; i < N; i++) {
        status = binary_search(k, ps, i);
        if (status) break;
    }

    // presentation
    if (ps[N - 1] % 10 != 0) std::cout << "No\n";
    else if (status) std::cout << "Yes\n";
    else std::cout << "No\n";           

    return 0;
}
