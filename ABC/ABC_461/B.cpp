#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    std::map<int, int> m;
    for (int i = 0; i < N; i++) {
        int b;
        std::cin >> b;
        if (m.count(b - 1) > 0) {
            std::cout << "No\n";
            return 0;
        }
        m[b - 1] = i + 1;
    }

    std::string ans = "Yes";
    for (int i = 0; i < N; i++) {
        if (m[i] != A[i]) {
            ans = "No";
            break;
        }
    };

    std::cout << ans << std::endl;

    return 0;
}
