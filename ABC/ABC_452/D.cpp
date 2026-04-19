#include <bits/stdc++.h>

using ll = long long;

int binary_search(int key, const std::vector<int> &A) {
    int left = -1; // i = 0 does not always satisfy condition
    int right = (int)A.size();
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (A[mid] >= key) right = mid; // argmin k (key < A[k]) *ascending
        else left = mid;
    }
    return right;
}

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int N = S.size();
    int M = T.size();

    std::map<char, std::vector<int>> m;
    for (int i = 0; i < N; i++) {
        m[S[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        bool status = true;
        int k = i; // init key
        for (int j = 0; j < M; j++) {
            const auto& A = m[T[j]]; // avoid copy
            int x = binary_search(k, A);
            if (x == (int)A.size()) { // key not found
                k = N - 1;
                status = false;
                break;
            }
            k = A[x];
            if (j < M - 1) k++; // update key
        }
        ans += (status) ? k - i : N - i;
    }

    std::cout << ans << std::endl;
    return 0;
}
