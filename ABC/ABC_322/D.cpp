#include <bits/stdc++.h>

using P = std::pair<int, int>;

int H = 4;
int W = 4;
bool isBound(int i, int j) { return (0 <= i && i < H && 0 <= j && j < W);}

int main() {
    int K = 3; // number of polyomino

    std::vector<std::vector<std::string>> S(K, std::vector<std::string>(W));
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < H; i++)
            std::cin >> S[k][i];
    }

    auto rotate = [&](int k) -> void { // 90 rotate the input in-place
        for (int i = 0; i < H; ++i)
            for (int j = i; j < W; ++j)
                std::swap(S[k][i][j], S[k][j][i]);
        for (auto& row : S[k])
            std::reverse(row.begin(), row.end());
    };

    std::vector<std::vector<std::vector<P>>> polms(K);
    auto get = [&]() -> void {
        for (int k = 0; k < K; k++) {
            int r = -1, c = -1;

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (S[k][i][j] == '#') {
                        r = i; c = j;
                        break;
                    }
                }
                if (r != -1) break;
            }

            std::vector<P> polm;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (S[k][i][j] == '#') {
                        polm.emplace_back(i - r, j - c);
                    }
                }
            }
            polms[k].push_back(polm);
        }
    };
   
    bool ans = false;
    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    auto dfs = [&](auto f, int k) -> void {
        if (k == K) { // all K polynomios attempted
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (G[i][j] == 0) return; // if not filled, false
                }
            }
            ans = true;
            return;
        }

        for (int r = 0; r < 4; r++) {
            for (int i0 = 0; i0 < H; i0++) {
                for (int j0 = 0; j0 < W; j0++) {

                    bool flg = true; // is valid path 
                    for (auto [i, j] : polms[k][r]) {
                        int ni = i + i0;
                        int nj = j + j0;
                        if (!isBound(ni, nj)) {
                            flg = false; // invalid -> polynomio ouside 
                            break;
                        }
                        if (G[ni][nj]) {
                            flg = false; // invalid -> polynomio overlaps
                        }
                    }
                    if (!flg) continue;

                    for (auto [i, j] : polms[k][r]) {
                        int ni = i + i0;
                        int nj = j + j0;
                        G[ni][nj]++;
                    }
                    f(f, k + 1);
                    for (auto [i, j] : polms[k][r]) {
                        int ni = i + i0;
                        int nj = j + j0;
                        G[ni][nj]--;
                    }

                    if (ans) return;
                }
            }
        }
    };
    
    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < K; i++) rotate(i);
        get();
    }

    dfs(dfs, 0);
    std::cout << (ans ? "Yes" : "No") << std::endl;

    return 0;
}

