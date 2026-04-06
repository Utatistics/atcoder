#include <bits/stdc++.h>

using P = std::pair<int, std::string>;

int main() {
    // input
    std::map<char, int> m;
    for (int i = 0; i < 5; i++) std::cin >> m[i + 'a'];

    // solve
    int N = 5;
    std::vector<P> x;
    for (int i = 0; i < (1 << N); i++) { // subset 0 to 2^N - 1 
        if (i == 0) continue;
        
        int s = 0; // score
        std::string n = ""; // name
        for (int j = 0; j < N; j++) { // checking jth bit of given i
            if (i & (1 << j)) { // apply mask (1 << j) to i (bit seq) to see if jth bit of i is active
                s += m[j + 'a'];
                n += std::toupper(j + 'a');
            }
        }
        x.push_back({s, n});
    }

    std::sort(x.begin(), x.end(),
          [](const P& a, const P& b) {
              if (a.first != b.first) return a.first > b.first; // larger int first
              return a.second < b.second; // smaller char (e.g. 'A' before 'Z')
          });

    // presentation
    for (auto [s, n] : x) std::cout << n << "\n"; 
    
    return 0;
}
