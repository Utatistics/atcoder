#include <bits/stdc++.h>

int main() {
    int A, B;
    std::cin >> A >> B;

    std::string ans = "Nein\n";
    if(A + B == 9) ans = "Nine\n";
    if(A - B == 9) ans = "Nine\n";
    if(A * B == 9) ans = "Nine\n";
    if(A / B == 9 && A % B == 0) ans = "Nine\n";

    std::cout << ans;

    return 0;
}

