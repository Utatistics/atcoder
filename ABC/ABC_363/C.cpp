#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int ans = 0;
    std::sort(S.begin(), S.end()); // lexicographical sort for next_perm 
    do { 
        bool hasPalindrome = false;
        for (int i = 0; i + K <= N; i++) {
            std::string s = "";
            std::string t = "";
            for (int j = 0; j < K; j++) {
                s += S[i + j];
                t += S[i + j];
            }
            std::reverse(t.begin(), t.end());
            bool isPalindrome = true;
            for (int i = 0; i < K; i++) {
                if (s[i] != t[i]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) {
                hasPalindrome = true;
                break;
            }
        }
        if(!hasPalindrome) ans++;
    } while (std::next_permutation(S.begin(), S.end()));
    
    std::cout << ans << std::endl;

    return 0;
}
