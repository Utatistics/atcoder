#include <bits/stdc++.h>

using P = std::pair<int, int>;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    auto f = [](int len) -> int { // returns max num of '?' to be filled with 'o'
        if (len <= 0) return 0;
        return (len + 1) / 2;
    };

    int cnt = 0; // counter for 'o'
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            ++cnt;
            continue;
        }

        bool l = (i > 0 && S[i - 1] == 'o');
        bool r = (i + 1 < N && S[i + 1] == 'o');

        if (S[i] == '?' && (l || r)) {
            S[i] = '.';
        }
    }
    int c = cnt; // constant cnt (i.e. lower bound for cnt)

    std::vector<P> W;
    std::vector<int> id(N, -1);
    for (int i = 0; i < N; i++) { // possibly addded 'o's given '?'s
        if (S[i] != '?') continue;

        int j = i;
        while (j < N && S[j] == '?') { // window of consecutive '?'s
            id[j] = (int)W.size();
            ++j;
        }

        W.emplace_back(i, j);
        cnt += f(j - i); // constant count + bonus
        i = j - 1;
    }

    std::string ans = S;
    for (int i = 0; i < N; i++) {
        if (ans[i] != '?') continue;

        auto [l, r] = W[id[i]]; // [l, r)
        int base = cnt - f(r - l);

        int maxd = base; // forcing '.' at i (e.g. ????.????)
        maxd += f(i - l);
        maxd += f(r - (i + 1));

        int maxo = base; // forching 'o' at i (e.g. ???.o.???)
        maxo += 1;
        maxo += f(i - l - 1);
        maxo += f(r - (i + 1) - 1);

        bool flgd = c <= K && K <= maxd;
        bool flgo = c + 1 <= K && K <= maxo;

        if (flgd && flgo) ans[i] = '?';
        else if (flgo) ans[i] = 'o';
        else ans[i] = '.';
    }

    std::cout << ans << '\n';
}
