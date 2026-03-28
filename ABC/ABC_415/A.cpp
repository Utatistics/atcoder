#include <bits/stdc++.h>

int main() {
    //inpu
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    int X;
    std::cin >> X;

    bool status = false;
    for (int i = 0; i < N; i++) {
        if (A[i] == X) stauts = true;
    }

    if (status) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}

