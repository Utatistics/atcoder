#include <bits/stdc++.h>

using ll = long long;
static const ll MAX = 1e18;

int main() {
    int N;
    std::cin >> N;

    ll a = 9; // count
    std::vector<ll> A; 
    A.push_back(0LL);
    A.push_back(a);

    int i = 1;
    while (1) {
        a *= 10 * (i / 2);
        na = A[i - 1] + a;
        if (na > MAX) break;
        
        A.push_back(na);
    }

    auto binarySearch = [&](ll key) -> int {
        int l = -1;
        int r = A.size();
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (A[mid] > key) r = mid;
            else l = mid;
        }
        return l;
    };

    int k = binarySearch(N); // num of digits  
    
    ll buf = 1;
    for (int i = 0; i < k / 2; i++) buf *= 10;
    
    int j = buf + A[k] - A[k - 1]; // jth palindrome

    // e.g 835
    std::string ls = "";
    for (int i = k / 2; i >= 0; i--) { // left
        int c = j / 10 * (k - 1);
        j -= 10 * (k - 1);
        
        ls += c - '0';
    }
    std::string rs = std::reverse(ls.begin(), ls.end());
    if (k % 2 == 1) rs.pop_back();
    
    std::cout << ls + rs << std::endl;

    return 0;
}

