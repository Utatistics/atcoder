#include <iostream>
#include <unordered_set>
#include <string>

int main () {
    int N;
    std::cin >> N;

    std::unordered_set<std::string> S;
    for (int i = 0; i < N; i++) {
        int n = S.size();
        std::string s;
        std::cin >> s;
        S.insert(s);
        if ((int)S.size() > n) std::cout << i + 1 << std::endl;
    }

    return 0;
}
