#include <bits/stdc++.h>

int main() {
    // input
    int N;
    std::cin >> N;

    std::vector<int> W(N);
    for (int i = 0; i < N; i++) std::cin >> W[i];

    // solve 
    std::vector<int> A;
    A.push_back(W[0]); // init
    for (int i = 1; i < N; i++) {
        int w = W[i];
        bool status = false;
        for (int j = 0; j < (int)A.size(); j++) {
            if (w <= A[j]) {
                A[j] = w;
                status = true;
                break;
            }
        }
        if (!status) {
            A.push_back(w);
        }
    }

    // presentaiton
    std::cout << (int)A.size() << std::endl;

    return 0;
}

