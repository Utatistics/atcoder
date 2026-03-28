#include <bits/stdc++.h>

int main() {
    // input ptocessing
    int N, K;
    std::cin >> N >> K;

    // solve
    int age = N;
    int c = age;

    while (c < K) {
        age++;
        c += age;
    }

    // presentation
    std::cout << age - N << std::endl;
    
    return 0;
}

