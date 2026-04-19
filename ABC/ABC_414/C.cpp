#include <bits/stdc++.h>

using ll = long long;

std::string toBase(int b, ll n) { // valid for b <= 10
   if (n == 0) return "0";
   std::string x;
   while (n > 0) {
       x += static_cast<char>('0' + (n % b)); // 
       n /= b;
   }
   std::reverse(x.begin(), x.end());
   return x;
}

bool isPal(std::string s) { // check if palindrome
    int n =  s.size();
    bool res = true;

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            res = false;
            break;
        }
    }

    return res;
}

int main() {
    // input
    int A;
    ll N;
    std::cin >> A >> N;

    // solve
    ll ans = 0;
    for (int i = 1; i < 1e6; i++) {
        std::string l = std::to_string(i);
        std::string r(l.rbegin(), l.rend());

        ll a = std::stol(l + r);
        ll b = std::stol(l + r.substr(1));
         
        if (a <= N && isPal(toBase(A, a))) ans += a;
        if (b <= N && isPal(toBase(A, b))) ans += b;
    }

    // presentation
    std::cout << ans << std::endl;

    return 0;
}

