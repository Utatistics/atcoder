#include <bits/stdc++.h>

using ll = long long;

int main() {
    // input processing
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    
    // solve
    std::sort(A.begin(), A.end(), [](int a, int b){ return a > b; }); // O(N * logN)
    
    // case 1
    int t = N - 1;
    for (int i = 0; i < N; i++) {
        if (A[i] == A[0]) continue;
        else {
            t = i;
            break;
        }
    }
    if ((N - t) % 2 == 0 || t == N - 1) {
        ll L = A[0];
        bool status = true;
        for (int i = t; i < (N - t) / 2; i++) {
            if(A[i] + A[(N - 1) - (i - t)] != L) {
                status = false;
                break;
            }
        }
        if (status) std::cout << L << " ";
    }

    // case 2
    if (N % 2 == 0) {
        ll L = A[0] + A[N - 1];
        bool status = true;
        for (int i = 1; i < N / 2; i++) {
            if (A[i] + A[N - 1 - i] != L) {
                status = false;
                break;
            }
        }
        if (status) std::cout << L;
    }

    std::cout << std::endl;
    return 0;
}

