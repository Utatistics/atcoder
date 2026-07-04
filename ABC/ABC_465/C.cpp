#include <bits/stdc++.h>

static const int MAX = 1e5 * 5;

int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> A(2 * MAX, 0);

    int l = MAX;
    int r = l + 1;
    A[l] = 1;

    bool flipped = false;
    for (int i = 2; i <= N; i++) {
        if (S[i - 1] == 'o') {
            if (!flipped) {
                A[l - 1] = i;
                --l;
            } else {
                A[r] = i;
                ++r;
            }
            flipped = !flipped;
        } else {
            if (!flipped) {
                A[l - 1] = i;
                --l;
            } else {
                A[r] = i;
                ++r;
            }
        }
    }

    if (flipped)
        for (int i = l; i < r; i++) std::cout << A[i] << " ";
    else
        for (int i = r - 1; i >= l; i--) std::cout << A[i] << " ";

    std::cout << std::endl;
    return 0;
}
