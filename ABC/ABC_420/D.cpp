#include <bits/stdc++.h>

using T = std::tuple<int, int, int>;

int H, W;
std::vector<std::vector<std::vector<char>>> A;

// up, down, left, right
static const int di[4] = {-1, 1, 0, 0};
static const int dj[4] = {0, 0, -1, 1};
bool isBound(int i , int j) { return (0 <= i && i < H && 0 <= j && j < W);}

std::vector<std::vector<std::vector<int>>> dist; // distance
std::vector<std::vector<std::vector<bool>>> visited; // visited with prev

void bfs(int si, int sj) {  
    std::queue<T> q; 
    dist.assign(H, std::vector<std::vector<int>>(W, std::vector<int>(2, -1))); // init with -1
    visited.assign(H, std::vector<std::vector<bool>>(W, std::vector<bool>(2, false))); // init with false
    
    q.push({si, sj, 0}); // {i, j, state}
    dist[si][sj][0] = 0;
    visited[si][sj][0] = true;
    
    while (!q.empty()) {
        auto [i, j, state] = q.front(); q.pop();
        int d = dist[i][j][state]; // current distance 
        if (A[i][j][state] == '?') state = std::abs(1 - state); // flip state if necessary
        
        for (int k = 0; k < 4; k++) { // grid search
            int id = i + di[k];
            int jd = j + dj[k];

            if (!isBound(id, jd)) continue;
            else if (visited[id][jd][state]) continue;
            else if (A[id][jd][state] == '#') continue;
            else if (A[id][jd][state] == 'x') continue;
            else { // 'o' or '.''
                dist[id][jd][state] = d + 1;
                visited[id][jd][state] = true;
                q.push({id, jd, state});

            }
        }
    }
}

int main() {
    // inpu t
    std::cin >> H >> W;

    int si = -1, sj = -1, gi = -1, gj = -1;
    A.resize(H, std::vector<std::vector<char>>(W, std::vector<char>(2)));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            std::cin >> c;

            if (c == 'S') {
                si = i;
                sj = j;
            }
            if (c == 'G') {
                gi = i;
                gj = j;
            }
            if (c == 'o' || c == 'x') {
                char d = (c == 'o') ? 'x' : 'o'; // flip
                A[i][j][0] = c;
                A[i][j][1] = d; // flipped
            }
            else {
                A[i][j][0] = c;
                A[i][j][1] = c;
            }
        }
    }

    // solve
    bfs(si, sj);

    // presentation
    int ans = 0;

    if (dist[gi][gj][0] != -1 && dist[gi][gj][1] != -1) // both valid 
        ans = std::min(dist[gi][gj][0], dist[gi][gj][1]);
    else if (dist[gi][gj][0] != -1 || dist[gi][gj][1] != -1) // either invalid
        ans = std::max(dist[gi][gj][0], dist[gi][gj][1]);
    else ans = -1; // both incalid

    std::cout << ans << std::endl;

    return 0;
}

