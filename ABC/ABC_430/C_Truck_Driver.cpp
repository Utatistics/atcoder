#include<iostream>
#include<string>
#include<vector>


int main() {
    int N, A, B;
    std::string s;
    std::cin >> N >> A >> B >> s;

    std::vector<int> sA(N + 1), sB(N + 1); // cumulative sum
    for (int i = 0; i < N; i++) if (s[i] == 'a') sA[i+1] = 1; else sB[i+1] = 1;
    for (int i = 0; i < N; i++) sA[i+1] += sA[i];
    for (int i = 0; i < N; i++) sB[i+1] += sB[i];

    long long ans = 0;
    for (int l = 0; l < N; l++) { // binary search
        int rA, rB;
        {
            int i = l, j = N + 1;
            while (j - i > 1) {
                int m = (i + j) /2;
                if (sA[m] - sA[l] >= A) j = m; else i = m;
            }
            rA = j;
        }
        {
            int i = l, j = N + 1;
            while (j - i > 1) {
                int m = (i + j) /2;
                if (sB[m] - sB[l] < B) i = m; else j = m;
            }
            rB = j;
        }
        ans += std::max(0, rB - rA);
    }

    std::cout << ans << std::endl;
    return 0;
}

