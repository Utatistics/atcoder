#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> m(N), im(N);
    for (int i = 0; i < N; i++) {
        int p;
        std::cin >> p;
        --p;

        m[i] = p;
        im[p] = i;
    }

    bool inv = false; // type 2 query flipps
    while (Q--) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int x, y;
            std::cin >> x >> y;
            --x; --y;

            if (!inv) {
                std::swap(m[x], m[y]);
                std::swap(im[m[x]], im[m[y]]);
            }
            else { // now, im is m !
                std::swap(im[x], im[y]);
                std::swap(m[im[x]], m[im[y]]);
            }
        }
        else 
            inv = !inv;
    }

    if (!inv) {
        for (int i = 0; i < N; i++) 
            std::cout << m[i] + 1 << " ";
    }
    else {
        for (int i = 0; i < N; i++) 
            std::cout << im[i] + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}

