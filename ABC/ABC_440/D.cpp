#include <bits/stdc++.h>

static const int INF = 2001001001; // X + Y ≈ 10^9 + 10^9 = 2 × 10^9

int binary_search(int key, const std::vector<int> &A, int i) {
    int left = i;
    int right = (int)A.size();

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if ((A[mid] - A[i]) - (mid - i) >= key) right = mid; // (# of integers in (A[i], A[mid]]) - (# of elements from A in that range)
        else left = mid;
    }
    return right;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    std:: sort(A.begin(), A.end());
    A.push_back(INF);

    while (Q--) {
        int X, Y;
        std::cin >> X >> Y;

        int i = lower_bound(A.begin(), A.end(), X) - A.begin(); // first i s.t. A[i] >= X

        // first seg: [X, A[i])
        if (Y <= A[i] - X) {
            std::cout << X + Y - 1 << '\n';
            continue;
        }

        // middle seg
        Y -= A[i] - X; // subtract skipped valid integers
        X = A[i] + 1; // A[i] cannot be used, so start from +1

        int k = binary_search(Y, A, i); 
        int j = k - 1; // // ans in the gap (A[j], A[k])

        // last seg: [A[j] + 1, ∞) 
        Y -= (A[j] - A[i]) - (j - i);
        X = A[j] + 1;

        std::cout << X + Y - 1 << '\n';
    }

    return 0;
 }
