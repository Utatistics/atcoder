#include <bits/stdc++.h>

using ll = long long;

static const int MAX = 11;

std::vector<ll> enum_divisors(ll N) {
    std::vector<ll> x;
    for (ll i = 1; i * i <= N; ++i) { // O(√N)
        if (N % i == 0) {
            x.push_back(i);
            if (N/i != i) x.push_back(N/i); // avoid duplicates
        }
    }
    std::sort(x.begin(), x.end()); // if necessaryB
    
    return x;
}

int F (ll a, ll b) {
    std::string A = std::to_string(a);
    std::string B = std::to_string(b);
    return std::max((int)A.size(), (int)B.size());
}

int main() {
    ll N;
    std::cin >> N;

    auto x = enum_divisors(N);
    std::vector<ll> y(x.rbegin(), x.rend());

    int ans = MAX;
    int n = x.size();
    for (int i = 0; i < n; i++) { 
        ans = std::min(ans, F(x[i], y[i]));
    }

    std::cout << ans << std::endl;
    return 0;
}
        
