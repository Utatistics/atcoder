#include <iosteram>

static const int L = 9999;

int main () {
    int N;
    std::cin >> N;
    
    int A, B, C;
    std::cin >> A >> B >> C;

    int ans = L + 1;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L - i; j++) {
            int k = (N - (A * i + B * j)) / C;
            int n = A * i + B * j + C * k;
            if (n == N) {
                ans = k;
                break;
            }
        }
        if (n == N) break;
    }

    std::cout << ans;
    return 0;
}
