#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int N = (int)S.size();

    int s = 0, t = 0;
    std::vector<int> cs(26), ct(26);
    for (int i = 0; i < N; i++) {
        if (S[i] == '@') ++s;    
        else cs[S[i] - 'a']++;
        
        if (T[i] == '@') ++t;    
        else ct[T[i] - 'a']++;
    }

    std::set<char> st{'a', 't', 'c', 'o', 'd', 'e', 'r'};
    for (int i = 0; i < 26; i++) {
        int diff = cs[i] - ct[i];
        if (diff == 0) continue;
        else {
            if (st.count((char)i + 'a') == 0) {
                std::cout << "No\n";
                return 0;
            }
        }

        if (diff > 0) {
            t -= diff;
        }
        else {
            s -= diff;
        }
    }

    if (s >= 0 && t >= 0) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

