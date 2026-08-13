#include <bits/stdc++.h>

using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll N, M, K;
    std::cin >> N >> M >> K;

    ll L = lcm(N, M);

    auto count = [&](ll x) {
        return x / N + x / M - 2 * (x / L);
    };

    auto binary_search = [&](ll key) -> ll{
        ll left = -1; // i = 0 does not always satisfy condition
        ll right = 1;
        while (count(right) < key) right *= 2; // 2^x to find right bound max

        while (right - left > 1) {
            ll mid = left + (right - left) / 2;
            if (count(mid) >= key) right = mid; // define solve elsewhere
            else left = mid;
        }
        return right;
    };

    ll ans = binary_search(K);
    std::cout << ans << std::endl;
    
    return 0;
}
