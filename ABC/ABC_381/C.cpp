#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;


    // solve
    std::vector<int> L;

    int cnt = 0;
    bool status = true;
    char prev = '2';
    for (auto it = S.begin(); it != S.end(); it++) {
        while () {
            
        }
        if (*it == '/') {
            L.push_back(cnt);
            continue;
        }
        if (prev == '2' && *it == '2') {
            cnt++;
        }
        prev = *it;
    }

    std::vector<int> R;

    return 0;
}

