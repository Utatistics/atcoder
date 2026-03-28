#include <bits/stdc++.h>

int digit_sum(const std::string& s) {
    int sum = 0;
    for (char c : s) sum += c - '0'; // char digit to int
    return sum;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        std::string s = std::to_string(i);
        int k = digit_sum(s);
        if (k == K) ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}

