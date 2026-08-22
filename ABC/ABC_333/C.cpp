#include <bits/stdc++.h>

using ll = long long;

int main() {
    int N;
    std::cin >> N;

    std::vector<ll> R;
    for (ll a = 1; a < 1e12; a = a * 10 + 1) {
        R.push_back(a);
    }
    
    std::set<ll> s;
    for (ll a : R) {
        for (ll b : R) {
            for (ll c : R) {
                s.insert(a + b + c);
            }
        }
    }
    std::vector<ll> d;
    for (ll x : s) d.push_back(x);
    std::cout << d[N - 1] << std::endl;
    return 0;
}

