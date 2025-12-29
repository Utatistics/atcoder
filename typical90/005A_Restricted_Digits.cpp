#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

int main() {
    int N, B, K;
    cin >> N >> B >> K;

    vector<int> C(K);
    for (int i = 0; i < K; i++) cin >> C[i];

    vector<vector<long long>> dp(N + 1, vector<long long>(B, 0));
    dp[0][0] = 1; // when no digit is selected, a single state of 'nothing'
    for (int i = 0; i < N; i++) { // i-th digit
        for (int j = 0; j < B; j++) { // current remainder
            if (dp[i][j] == 0) continue; // optimization
            for (int k = 0; k < K; k++) { // choose digit
                int r = (10 * j + C[k]) % B;
                dp[i + 1][r] = (dp[i + 1][r] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[N][0] << endl;
    return 0;
}

