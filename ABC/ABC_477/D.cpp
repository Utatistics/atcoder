#include <bits/stdc++.h>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::string ans(N, 'a');
    
    int last = -1; // the most recent paint query (type2)
    char c  = 'a'; // the color
    
    std::vector<int> time(N, -1); // the most recent tile removal
    std::vector<bool> tile(N, false); // covered/removed

    int ts = 0; // tiome stamp
    while (Q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int x;
            std::cin >> x;
            --x;

            if (!tile[x]) { // paint a new color when covering 
                if (time[x] < last) ans[x] = c; // unless it was covered when painted 
            } else {
                time[x] = ts;
            }

            tile[x] = !tile[x]; // flip covered/uncovered
        }
        else {
            last = ts;
            std::cin >> c;
        }
        ++ts;
    }
    for (int i = 0; i < N; i++){
        if (!tile[i]) {
            if (time[i] < last) ans[i] = c;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}

