#include <bits/stdc++.h>

int main() {
    // input processing
    int N, M;
    std::cin >> N >> M;
    
    std::string S, T;
    std::cin >> S >> T;

    int Q;
    std::cin >> Q;

    // solve
    for (int i = 0; i < Q; i++) {
        bool takahashi = true;
        bool aoki = true;
        std::string W;
        std::cin >> W;
        for (char w : W) {
            if(S.find(w) == std::string::npos) takahashi = false;
            if(T.find(w) == std::string::npos) aoki = false;
        }

        // presentation
        if (takahashi && aoki)
            std::cout << "Unknown\n";
        else if (takahashi)
            std::cout << "Takahashi\n";
        else if (aoki)
            std::cout << "Aoki\n";
    }

    return 0;
}

