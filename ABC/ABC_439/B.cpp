#include <bits/stdc++.h>

int happify(int n, std::map<int, int> & m) {
    if (n == 1) return 1;
    if (m[n] > 1) return -1;
    
    int sum = 0;
    std::string s = std::to_string(n);
    for (char c : s) {
        sum += (c - '0') * (c - '0');
    } 

    // visited
    m[sum] += 1;  

    return happify(sum, m);
}

int main() {
    int N;
    std::cin >> N;
    
    // solve 
    std::map<int, int> s;
    int res = happify(N, s);

    // presentation
    if (res == 1)
        std::cout << "Yes" << std::endl;
    else if (res == -1)
        std::cout << "No" << std::endl;
    
    return 0;
}

