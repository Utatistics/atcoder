#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    int Q;
    std::cin >> Q;

    std::vector<int> A(N); // pigeon -> locial
    std::vector<int> B(N); // physical -> logical
    std::vector<int> C(N); // logical -> physical

    for (int i = 0; i < N; i++) { // init
        A[i] = i;
        B[i] = i;
        C[i] = i;
    }

    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) { // move pigeon
            int a, b;
            std::cin >> a >> b;
            --a; --b;

            A[a] = B[b];
        }
        else if (t == 2) { // move nest
            int a, b;
            std::cin >> a >> b;
            --a; --b;

            int la = B[a];
            int lb = B[b];

            std::swap(B[a], B[b]);
            std::swap(C[la], C[lb]);
        }
        else {
            int a;
            std::cin >> a;
            --a;

            std::cout << C[A[a]] + 1 << "\n";
        }
    }

    return 0;
}
