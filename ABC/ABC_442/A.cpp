#include <bits/stdc++.h>

int main() {
    // input processing
    std::string S;
    std::cin >> S;

    // solve
    int ans = 0;
    for (char c : S) {
        if (c == 'i' || c == 'j') ans++;
    }

    // presentation
    std::cout << ans << std::endl;
    
    return 0;
}

