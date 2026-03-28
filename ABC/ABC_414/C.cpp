#include <bits/stdc++.h>

using ll = long long;

std::string toBase(ll n, int b) {
   if (n == 0) return "0";
   string x;
   while (n > 0) {
       x += char('0' + (n % b));
       n /= b;
   }
   std::reverse(x.begin(), x.end());
   return x;
}

bool isPal(std::string s) { // check if palindrome
    return status;
}

int main() {
    // input
    int A, N;
    std::cin >> A >> N;

    // solve
    ll ans = 0;
    std::string s = std::to_string(N);
    int d = s.size();

    ll = n;
    while (n < N) {
        // construct base 10 palindrome
    
        // convert to base A
        std::string nb = toBase(n, A);
        
        // check
        if (isPal(nb)) ans++;
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

