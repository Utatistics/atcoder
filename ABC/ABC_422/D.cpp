#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> p;

    for (int i = 0; i < (1 << N); i++) {
        int x = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) 
                x |= (1 << (N - 1 - j));
    }
    p.push_back(x);
}

    int mod = K % (1 << N);

    int U = (mod == 0) ? 0 : 1;
    std::vector<int> B(1 << N, K / (1 << N));
    for (int i = 0; i < mod; i++) B[p[i]]++;

    std::cout << U << std::endl;
    for (int b : B) std::cout << b << " ";
    std::cout << std::endl;
}
