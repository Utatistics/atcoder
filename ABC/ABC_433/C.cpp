#include <bits/stdc++.h>

int main() {
    // input processing
    std::string S;
    std::cin >> S;

    // solve
    int N = S.size();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sl = S[i] - '0';
        int sr = S[i + 1] - '0';

        int c = 0;
        if (sl + 1 == sr) {
            c++;

            int cl = 0;
            for (int j = i - 1; j >= 0 ; j--) {
                if (S[i] == S[j]) cl++;
                else break;
            }
            int cr = 0;
            for (int k = i + 2; k < N ; k++) {
                if (S[i + 1] == S[k]) cr++;
                else break;
            }
            c += std::min(cl, cr);
        }

        ans += c;
    }

    // presentation
    std::cout << ans << std::endl;
    return 0;
}
