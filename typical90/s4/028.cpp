#include <iostream>
#include <vector>

static const int L = 1e3;

int main () {
    int N;
    std::cin >> N;

    // init
    std::vector<std::vector<int>> a(L + 1, std::vector<int>(L + 1, 0));
    for (int i = 0; i < N; i++) { // init imos matrix
        int lx, ly, rx, ry;
        std::cin >> lx >> ly >> rx >> ry;
        a[lx][ly] += 1; a[rx][ry] += 1;
        a[lx][ry] -= 1; a[rx][ly] -= 1;
    }

    // solve
    for (int  i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) if (j != 0) a[i][j] += a[i][j - 1];
    }
    for (int  i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) if (i != 0) a[i][j] += a[i - 1][j];
    }
    
    // presentation
    std::vector<int> ans(N +1);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            int k = a[i][j];
            ans[k] += 1;
        }
    }    
    for (int i = 1; i <= N; i++) std::cout << ans[i] << std::endl;

    return 0;
}

