#include <bits/stdc++.h>

using ll = long long;
static const int M = 1e5;

int digit_sum(const std::string& s) {
    int sum = 0;
    for (char c : s) sum += c - '0'; // char digit to int
    return sum;
}

int main() {
    // input
    int N;
    std::cin >> N;
    ll K;
    std::cin >> K;

    // solve
    std::vector<int> v(M, -1); // steps for 1st vist, -1 if unvisited
    std::vector<int> path; // path til detect the cycle 
    int step = 0;
    int x = N; // init;
    while (1) { // O(M)
        if (v[x] >= 0) break; // i.e. entering cycle at step = v[x]
        v[x] = step;
        path.push_back(x);

        int y = digit_sum(std::to_string(x));
        int z = (x + y) % M;

        step++;
        x = z; // display
    }

    // presentation
    int s = v[x]; // start of cycle
    int k = step - s; // cycle length

    int ans;
    if (K < s) {
        ans = path[K];
    } else {
        K -= s;
        ans = path[s + (K % k)];
    }

    std::cout << ans << std::endl;

    return 0;
}
