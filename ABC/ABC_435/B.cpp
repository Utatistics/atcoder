#include <bits/stdc++.h>

// mathematical modulo (safely assume [0, b-1])
int mod(int a, int b) {return (a % b + b) % b;}

int main() {
    // input processing
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) 
        std::cin >> A[i];

    std::vector<int> ps(N);
    for (int i = 0; i < N; i++) 
        ps[i] = (i == 0) ? A[i] : ps[i - 1] + A[i];
    
    // solve
    int s = 0;
    int ans = 0;
    for (int r = 0; r < N; r++) {
        for (int l = 0; l <= r; l++) {
            s = (l != 0) ? ps[r] - ps[l - 1] : ps[r];
            // std::cout << "l=" << l+1 << ", r=" << r+1 << ", s=" << s << std::endl;
   
            // judge
            int i = l;
            bool status = false;
            while (i <= r) {
                status = mod(s, A[i++]) == 0; // true if divisor
                if (status) break;
            }
            ans += (status) ? 0 : 1;
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}
