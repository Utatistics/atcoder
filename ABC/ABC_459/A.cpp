#include <bits/stdc++.h>

int main() {
    int X;
    std::cin >> X;
    X--;

    std::string ans = "";
    std::string s = "HelloWorld";
    for (int i = 0; i < 10; i++) 
        if (i != X) ans += s[i];
    
    std::cout << ans << std::endl;
    return 0;
}

