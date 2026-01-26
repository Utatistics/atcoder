#include <bits/stdc++.h>

using ll = long long;

ll base8to10(const std::string& d08) { // base-8 string → decimal
    ll d10 = 0;
    for (char c : d08) {
        d10 = d10 * 8 + (c - '0');
    }

    return d10;
}

std::string base10to9(ll d10) { // decimal → base-9 string
    if (d10 == 0) return "0";

    std::string d09 = "";
    while (d10 > 0) {
        int m = (d10 % 9 == 8)? 5 : d10 % 9;
        d09.push_back('0' + m);
        d10 /= 9;
    }
    reverse(d09.begin(), d09.end()); // O(N)
    return d09;
}

int main() {
    // input processing
    std::string N;
    std::cin >> N;
    
    int K;
    std::cin >> K;

    // solve
    ll d10;
    std::string d08 = N;
    // std::string d09;
    for (int i = 0; i < K; i++) {
        d10 = base8to10(d08);
        d08 = base10to9(d10);
        // d08 = d09; 
    }

    // presentation
    std::cout << d08 << std::endl;

    return 0;
}

