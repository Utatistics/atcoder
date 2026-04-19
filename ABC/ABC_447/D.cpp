#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int N = S.size();

    std::queue<int> A, B, C;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == 'A') A.push(i);
        else if (c == 'B') B.push(i);
        else C.push(i);
    }

    int ans = 0;
    while (!A.empty()) {
        int a = A.front(); A.pop();
        
        int b = a;
        while (!B.empty() && a >= b) {
            b = B.front(); B.pop();
        }
        if (a >= b) break;

        int c = b;
        while (!C.empty() && b >= c) {
            c = C.front(); C.pop();
        }
        if (b >= c) break;

        ans++;
    }

    std::cout << ans << std::endl;
    return 0;
}

