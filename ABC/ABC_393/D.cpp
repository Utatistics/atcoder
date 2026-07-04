#include <bits/stdc++.h>

using P = std::pair<char, int>;

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<std::pair<char,int>> rle;
    rle.push_back({S[0], 1});
    for (int i = 1; i < N; i++) {
        if (S[i] == rle.back().first) rle.back().second++;
        else rle.push_back({S[i], 1});
    }
    
    char l = rle[0];
    char r = rle.back();

    while () {
        P p = rle[l]; q = rle[r];
        if (p.first == '0')
        
    }
    return 0;
}

