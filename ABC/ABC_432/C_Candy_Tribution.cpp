#include<iostream>
#include<algorithm>
#include<vector>

int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    std::vector<int> A;

    bool status = true;
    int minA = 1e9;
    int r = 0; // remainder    
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A.push_back(a);
        
        minA = std::min(a, minA);
        int r_current = r; r = (a * Y) % (Y - X);
        if (r_current != r && i != 0) status = false;
    }
    
    long long ans;
    for (int i = 0; i < N; i++) {
        int la = A[i] - ((A[i] - minA) * Y / (Y - X));
        if (la < 0) { // length check
            status = false;
            break;
        }
        ans += la;        
    }
        
    if (!status) ans = -1;
    std::cout << ans;
    
    return 0;
}
