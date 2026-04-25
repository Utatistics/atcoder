#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int N = S.size();

    std::deque<int> dq;
    for (int i = 0; i < N; i++) {
        if (S[i] > T[i]) dq.push_back(i);   
    }
    for (int i = N - 1; i >= 0; i--) { 
        if (S[i] < T[i]) dq.push_back(i);
    }

    std::vector<std::string> A;
    A.push_back(S); // init 
    while (!dq.empty()) {
        int x = dq.front(); dq.pop_front();
        
        std::string s = A.back();
        s[x] = T[x]; // update
        A.push_back(s);
    }

    int M = A.size();
    std::cout << M - 1 << std::endl;
    for (int i = 1; i < M; i++) {
        std::cout << A[i] << std::endl;
    }

    return 0;
}

