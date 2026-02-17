#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int s = 0;
    for (int i = 1; i <= N; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        s += sign * i * i * i;  // i^3 manually
    }

    std::cout << s;
}


