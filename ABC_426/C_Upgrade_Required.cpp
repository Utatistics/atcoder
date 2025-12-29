#include <iostream>
#include <vector>

int upgrade(std::vector<int> &v, int X, int Y) {  // return type changed to int
    int n = v.size();
    int lwr = 0;
    int upr = n - 1;
    int k = -1;

    while (true) {
        int mid = (lwr + upr) / 2;
        int lwr0 = lwr; int upr0 = upr;
        
        if (v[mid] == X) { // switch to linear search
            for (int i = mid; i < n; i++) {
                if (v[i] > X) {
                    k = mid;
                    break;
                }
            }
        } else if (v[mid] < X) {
            lwr = mid + 1;
            if (lwr > lwr0) { // switch to linear
            }
        } else if (v[mid] > X) {
            upr = mid;
            if (upr < upr0) { // switch to linear
            }
        }
    }
    for (int i = 0; i < k - 1; i++) v[i] = Y;
    return k;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> os(N);
    for (int i = 0; i < N; i++) os[i] = i;
    
    int X, Y;
    for (int i = 0; i < Q; i++) {
        std::cin >> X >> Y;
        int cnt = upgrade(os, X, Y);
        std::cout << cnt;
    }

    return 0;
}

