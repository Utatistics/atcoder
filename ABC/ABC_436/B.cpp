#include <bits/stdc++.h>

int mod (int a, int b) {return (a % b + b) % b;}

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N * N);
    for (int i = 0; i < N; i++) { // H for rownum
        for (int j = 0; j < N; j++) { // W for colnum
            A[j + i * N] = -1; // init
        }
    }

    // solve
    /// init
    int r = 0;
    int c = (N - 1) / 2;
    int k = 1;
    A[c + r * N] = k;
    int cnt = 0; // count of operationi
    
    while (cnt < N * N - 1) {
        k++;
        int i = mod(r - 1, N); // gurantee a > 0 for a % b
        int j = mod(c + 1, N);

        if (A[j + i * N] < 0) {
            A[j + i * N] = k;
            r = i; c = j;
        } else {
            i = mod(r + 1, N);
            j = c;
            A[j + i * N] = k;
            r = i; c = j;
        }
        cnt++;
    }

    // presentation
    for (int i = 0; i < N; i++) { // H for rownum
        for (int j = 0; j < N; j++) { // W for colnum
            std::cout << A[j + i * N] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

