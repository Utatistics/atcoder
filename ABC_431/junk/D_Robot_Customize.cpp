#include<iostream>
#include<cstdlib>
#include<vector>
#include<utility>
#include<set>

int main () {
    int N;
    std::cin >> N;
    std::vector<int> W, H, B;
    std::multiset<std::pair<int, int>> diff; // {diff, id}
    std::vector<int> ans(N); // 0 = head, 1 = body
    for (int i = 0; i < N; i++) {
        int w, h, b;
        std::cin >> w >> h >> b;
        W.push_back(w);
        H.push_back(h);
        B.push_back(b);
        diff.insert({std::abs(h - b), i});
        ans[i] = (h >= b) ? 0 : 1;
    }
    
    int wH, wB, hp;
    while(true) {
        wH = wB = hp = 0; // reset totals each iteration
        for (int i = 0; i < N; i++) {
            std::cout << i << " " << wH << " " << wB << " " << hp << "\n"; // debug
            if(ans[i] == 0) {
                wH += W[i];
                hp += H[i];   
            }
            else {
                wB += W[i];
                hp += B[i];   
            }
        }
        if (wH <= wB) {
            std::cout << hp;
            break;
        }
        else {
            auto p = *diff.begin();
            ans[p.second] = 1 - ans[p.second]; // flip head/body
        }
    }
}
